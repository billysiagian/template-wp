<?php

// $Id: post.inc 2784 2013-11-21 10:48:22Z cimorrison $

// Convert MONTHLY_SAMEDAY repeats into MONTHLY repeats with a specified month_relative (eg '2TU')

require "standard_vars.inc.php"; // to ensure the timezone is set

global $tbl_repeat, $tbl_area, $tbl_room;

// Get all the monthly sameday repeats.
$sql = "SELECT T.id, T.start_time, A.timezone
          FROM $tbl_repeat T, $tbl_area A, $tbl_room M
         WHERE T.rep_type=5
           AND T.room_id=M.id
           AND M.area_id=A.id";
 
$res = sql_query($sql);

if ($res === FALSE)
{
  trigger_error(sql_error(), E_USER_WARNING);
  fatal_error(FALSE, get_vocab("fatal_db_error"));
}

// Save the current default timezone so that we can restore it at the end
$old_tz = mrbs_default_timezone_get();

$mods = array();

for ($i = 0; ($row = sql_row_keyed($res, $i)); $i++)
{
  // We need to make sure that we have the correct timezone set when we work out
  // the day of the month that this series repeats on
  if (!empty($row['timezone']))
  {
    mrbs_default_timezone_set($row['timezone']);
  }
  $mods[$row['id']] = date_byday($row['start_time']);
}

foreach ($mods as $id => $month_relative)
{
  $sql = "UPDATE $tbl_repeat
             SET month_relative='" . sql_escape($month_relative) . "',
                 rep_type=" . REP_MONTHLY . "
           WHERE id=$id";
  if (sql_command($sql) < 0)
  {
    trigger_error(sql_error(), E_USER_WARNING);
    fatal_error(FALSE, get_vocab("fatal_db_error"));
  }
}

// Restore the original timezone
mrbs_default_timezone_set($old_tz);
