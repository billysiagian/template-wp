<?php

// $Id: version.inc 2841 2014-06-18 19:41:39Z jberanek $

// This should probably be a class, but you can only have protected
// class members in PHP 5, so we won't bother

function get_mrbs_version()
{
  // MRBS developers, make sure to update this string before each release
  $mrbs_version = "MRBS 1.4.11";

  return $mrbs_version;
}

