<?php
// Monday of First Week
$day = 18;
$month = 1;
$year = 2015;

$class_weekdays = array('Monday', 'Tuesday', 'Wednesday', 'Friday');

?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
    <link rel="stylesheet" type="text/css" href="style.css">
    <title>CSC 161:  Imperative Problem Solving and Data Structures</title>
    <link rev="made" href="mailto:walker@cs.grinnell.edu">
</head>

<body>
<div class="body">
<?php

// insert course header file
readfile("header.inc");

?>
<div class="labcontent">
<?php
// initialize day-of-week processing
$all_days = array('Sunday', 'Monday', 'Tuesday', 'Wednesday', 
                      'Thursday', 'Friday', 'Saturday');

// initialize date-by-date processing
date_default_timezone_set('America/Chicago');
$sunday_of_week = mktime(0,0,0,$month,$day,$year);

$sched_file = fopen ("sched", "r");
?>

<H1>Tentative Class Schedule</H1>

<table border width="100%">
<tr>
<?php
// print weekday headers
$num_days = count ($class_weekdays);  // number of class days per week
$col_width = 100.0 / $num_days;       // percentage of width per day
$class_day_count = -1;                // class days are 0-indexed

$start_of_schedule = false;
$days_from_Sunday = array();

// print days of class
// and compute array with days from Sunday
for ($i = 0; $i < $num_days; $i++)
{
   echo "   <th width=\"$col_width;%\">$class_weekdays[$i]\n";
   $day_found = false;
   for ($j = 0; !$day_found && $j < count($all_days); $j++)
   {
      if ($class_weekdays[$i] == $all_days[$j])
      {  
         $days_from_sunday[$i] = $j;
	 $day_found = true;
      }
   }
}
?>
</tr>

<?php

$start_of_calendar = true;

while (!feof($sched_file))
{
   $line = fgets($sched_file);
   if ($start_of_calendar || $line == "\n")
   {
      $class_day_count++;
      $class_day_of_week = $class_day_count % $num_days; // class number within week
      if ($class_day_of_week == 0)
      {
          // echo "<tr><td>" . date ("j F", $sunday_of_week) . "&mdash; </tr>";
          if (!$start_of_calendar)
          {
             echo "</tr>\n\n";
             // move to next week
             $sunday_of_week = strtotime ("+1 week", $sunday_of_week);
          }
          if (!feof($sched_file))
          {
             $start_of_calendar = false;
             echo "<tr>\n";
          }
      }
      $current_day = $days_from_sunday[$class_day_of_week];
      
      echo "<td valign=top><b>"
            // . $current_day . " : "
            // . date ("F j", $sunday_of_week) . " : " 
            // . $class_weekdays[$class_day_of_week] . ", "
            . date ("F j", strtotime("+$current_day day",
                    $sunday_of_week)) . "</b>";

   }
   if ($line != "\n")
   {
         echo  "     <br>" . $line;
   }

}
?>

<?php
fclose($sched_file);

?>
</tr>
</table>

<?php
// insert course footer file
readfile("footer-schedule.inc");
?>

</body>
</html>
