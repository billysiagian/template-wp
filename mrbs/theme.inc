<?php

// $Id: theme.inc 2784 2013-11-21 10:48:22Z cimorrison $

// Gets the styling appropriate to the theme.     If there isn't a styling file
// present for the theme then the default styling is used.

require_once "systemdefaults.inc.php";
require_once "config.inc.php";
require_once "Themes/default/styling.inc";
@include_once "Themes/$theme/styling.inc";   // overwrite the default with the specified styling if it exists

