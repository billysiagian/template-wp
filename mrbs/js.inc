<?php 

// $Id: js.inc 2811 2014-02-08 11:38:34Z cimorrison $


// We need to construct a standard query string that can be passed to the *.js.php
// pages.  That's because some of the settings they use are area dependent.
// We also want the area to be in the queey string so that the JavaScript page is
// cached if the area is the same and not otherwise.
$standard_query_string = "area=$area";
  
  
  
// We are using the jQuery UI library, which has been custom built to include the following components:
//   - Core
//   - Widget
//   - Mouse
//   - Position
//   - Draggable
//   - Resizable
//   - Autocomplete
//   - Button
//   - Datepicker
//   - Dialog
//   - Menu
//   - Tabs
//   - Sunny theme
// If you need any other components you will need to rebuild the custom UI library
// See http://jqueryui.com/
?>

<!--[if (!IE)|(gt IE 8)]><!-->
  <script type="text/javascript" src="jquery/jquery-2.1.0.min.js"></script>
<!--<![endif]-->

<!--[if lte IE 8]>
  <script type="text/javascript" src="jquery/jquery-1.11.0.min.js"></script>
<![endif]-->

<?php
// We need the migration script now that we are running jQuery 1.9+, or at least
// until we are confident that our JavaScript is not using any features that have
// been removed.   The uncompressed version will output warnings about removed and
// deprecated features to the console
if (DEBUG)
{
  ?>
  <script type="text/javascript" src="jquery/jquery-migrate-1.2.1.js"></script>
  <?php
}
else
{
  ?>
  <script type="text/javascript" src="jquery/jquery-migrate-1.2.1.min.js"></script>
  <?php
}
?>
<script type="text/javascript" src="jquery/ui/jquery-ui-1.10.4.custom.min.js"></script>
<script type="text/javascript" src="jquery/ui/jquery-ui-i18n.js"></script>
<?php
// Extra regional settings for the jQuery UI datepicker
?>
<script type="text/javascript" src="jquery/ui/jquery-ui-i18n.MRBS.js"></script>

<?php // Work out if we're using IE6 or below ?>
<script type="text/javascript">
  //<![CDATA[
  var lteIE6 = false;
  //]]>
</script>
<!--[if lte IE 6]>
<script type="text/javascript">
  //<![CDATA[
  var lteIE6 = true;
  //]]>
</script>
<![endif]-->
    
<?php // Work out if we're using IE7 or below ?>
<script type="text/javascript">
  //<![CDATA[
  var lteIE7 = false;
  //]]>
</script>
<!--[if lte IE 7]>
<script type="text/javascript">
  //<![CDATA[
  var lteIE7 = true;
  //]]>
</script>
<![endif]-->
    
<?php // Work out if we're using IE8 or below ?>
<script type="text/javascript">
  //<![CDATA[
  var lteIE8 = false;
  //]]>
</script>
<!--[if lte IE 8]>
<script type="text/javascript">
  //<![CDATA[
  var lteIE8 = true;
  //]]>
</script>
<![endif]-->
    
<script type="text/javascript">
  //<![CDATA[
  <?php
  // Create an empty init() function.   This will get "extended" if necessary
  // by the page specific JavaScript files in the js directory
  ?>
  function init(params)
  {
  }
  //]]>
</script>

<?php
// All pages
?>
<script type="text/javascript" src="js/functions.js.php?<?php echo $standard_query_string ?>"></script>
<script type="text/javascript" src="js/datepicker.js.php?<?php echo $standard_query_string ?>"></script>
<script type="text/javascript" src="js/general.js.php?<?php echo $standard_query_string ?>"></script>

    
<?php
// dataTables initialisation
if (in_array($page, array('admin', 'edit_users', 'pending', 'report', 'search')))
{
  // Include the JavaScript for those pages that use dataTables
  ?>
  <script type="text/javascript" src="jquery/datatables/js/jquery.dataTables.min.js"></script>
  <script type="text/javascript" src="jquery/datatables/js/ColReorder.min.js"></script>
  <?php
  // We use a customised version of ColVis which fixes a problem to do with the width of the
  // ColVis collection div meaning that when you have long column names the collection
  // buttons spill over onto multiple lines.   This problem has been reported in the
  // DataTables forum and hopefully the fix will appear in a future release (or else an
  // alternative solution suggested).  In the meantime we use the mrbs version of ColVis,
  // which is kept separate so that we can identify the differences.
  /*
  <script type="text/javascript" src="jquery/datatables/js/ColVis.min.js"></script>
  */
  ?>
  <script type="text/javascript" src="jquery/datatables/js/ColVis.mrbs.min.js"></script>
  <?php
  // We also have a customised version of FixedColumns which fixes a problem to do with the
  // resizing of windows in IE7/8.   The problem has been reported.
  /*
  <script type="text/javascript" src="jquery/datatables/js/FixedColumns.min.js"></script>
  */
  ?>
  <script type="text/javascript" src="jquery/datatables/js/FixedColumns.mrbs.js"></script>
  <script type="text/javascript" src="jquery/datatables/js/plugins.js"></script>
      
  <script type="text/javascript" src="js/datatables.js.php?<?php echo $standard_query_string ?>"></script>

  <?php
}
    
    
// Get any page specific JavaScript
if (file_exists("js/$page.js"))
{
  ?>
  <script type="text/javascript" src="js/<?php echo $page?>.js"></script>
  <?php
}
if (file_exists("js/$page.js.php"))
{
  ?>
  <script type="text/javascript" src="js/<?php echo $page?>.js.php?<?php echo $standard_query_string ?>"></script>
  <?php
}
    
    
// We need the resizable booking, multiple bookings and refresh code for the day and week pages
if (in_array($page, array('day', 'week')))
{
  ?>
  <script type="text/javascript" src="js/refresh.js.php?<?php echo $standard_query_string ?>"></script>
  <script type="text/javascript" src="js/resizable.js.php?<?php echo $standard_query_string ?>"></script>
  <script type="text/javascript" src="js/multiple.js.php?<?php echo $standard_query_string ?>"></script>
  <?php
}
    
if (in_array($page, array('day', 'week', 'month')))
{
  ?>
  <script type="text/javascript" src="js/cell_click.js.php?<?php echo $standard_query_string ?>"></script>
  <?php
}
?>  
    
<script type="text/javascript">

//<![CDATA[





$(window).on('load', function() {

  var args = {day: '<?php echo $day?>',
              month: '<?php echo $month?>',
              year: '<?php echo $year?>',
              area: '<?php echo $area?>',
              room: '<?php echo $room?>',
              page: '<?php echo $page?>'};
  <?php
  // We need $timetohighlight for the day and week pages
  $timetohighlight = get_form_var('timetohighlight', 'int');
  if (isset($timetohighlight))
  {
    ?>
    args.timetohighlight = '<?php echo $timetohighlight?>';
    <?php
  }
  ?>
  init(args);

});


//]]>
</script>