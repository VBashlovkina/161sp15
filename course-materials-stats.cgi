#!/bin/bash

echo
echo Approximate statistics for CSC 161 materials 
echo "     " `date +'%I:%M %p on %A, %B %d, %Y'`

echo
echo "Course home directory:  `pwd`"
echo
echo "                          files lines  characters"

#Web page statistics
numFiles=`ls *html */*html */*/*html | wc -l`
totFiles=$numFiles
numLines=`cat *html */*html */*/*html | wc -l`
totLines=$numLines
numChars=`cat *html */*html */*/*html | wc -c`
totChars=$numChars
echo "Web pages (html/shtml):    $numFiles  $numLines   $numChars"

#Lab statistics
numFiles=`ls */lab-*html */*/lab-*html | wc -l`
numLines=`cat */lab-*html */*/lab-*html | wc -l`
numChars=`cat */lab-*html */*/lab-*html | wc -c`
echo "                  labs:     $numFiles  $numLines    $numChars"

#Reading statistics
numFiles=`ls */reading-*html */*/reading-*html | wc -l`
numLines=`cat */reading-*html */*/reading-*html | wc -l`
numChars=`cat */reading-*html */*/reading-*html | wc -c`
echo "              readings:     $numFiles   $numLines    $numChars"

#Diagrams and images
numFiles=`ls *png *jpg *gif */*png *.*jpg */*gif */*/*png */*/*png */*/*jpg */*/*gif | wc -l`
((totFiles+=$numFiles))
echo "Diagrams/images:            $numFiles    N/A       N/A"

#Course schedule
numFiles=`ls sched schedule.php | wc -l`
((totFiles+=$numFiles))
numLines=`cat sched schedule.php | wc -l`
((totLines+=$numLines))
numChars=`cat sched schedule.php | wc -c`
((totChars+=$numChars))
echo "Course schedule:             $numFiles    $numLines     $numChars"

#Supporting include files
numFiles=`ls *.inc */*/*.inc | wc -l`
((totFiles+=$numFiles))
numLines=`cat *.inc */*/*.inc | wc -l`
((totLines+=$numLines))
numChars=`cat *.inc */*/*.inc | wc -c`
((totChars+=$numChars))
echo "Supporting include files:   $numFiles   $numLines     $numChars"

#CSS style sheet
numFiles=`ls *.css | wc -l`
((totFiles+=$numFiles))
numLines=`cat *.css | wc -l`
((totLines+=$numLines))
numChars=`cat *.css | wc -c`
((totChars+=$numChars))
echo "CSS style sheet:             $numFiles    $numLines      $numChars"

#C programs
numFiles=`ls *.c */*.c */*/*.c | wc -l`
((totFiles+=$numFiles))
numLines=`cat *.c */*.c */*/*.c | wc -l`
((totLines+=$numLines))
numChars=`cat *.c */*.c */*/*.c | wc -c`
((totChars+=$numChars))
echo "C programs*:               $numFiles  $numLines    $numChars"

#C header files 
numFiles=`ls *.h */*.h */*/*.h | wc -l`
((totFiles+=$numFiles))
numLines=`cat *.h */*.h */*/*.h | wc -l`
((totLines+=$numLines))
numChars=`cat *.h */*.h */*/*.h | wc -c`
((totChars+=$numChars))

echo "C header files*:            $numFiles   $numLines     $numChars"  
echo "                           ---  -----   -------"
echo "Totals:                    $totFiles  $totLines   $totChars"
echo
echo
echo "* these totals do not count the infrastructure for the MyroC header and implementation files"
