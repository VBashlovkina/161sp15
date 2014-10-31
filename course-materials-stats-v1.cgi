#!/bin/bash

echo
echo Approximate statistics for CSC 161 materials 
echo "     " `date +'%I:%M %p on %A, %B %d, %Y'`

echo
echo "Course home directory:  `pwd`"
echo
echo "                        files lines characters"

echo "Web pages (html/shtml):  "  `ls *html */*html */*/*html | wc -l` `cat *html */*html */*/*html | wc -l -c`
echo "                  labs:   "  `ls */lab-*html */*/lab-*html | wc -l` `cat */lab-*html */*/lab-*html | wc -l -c`
echo "              readings:   "  `ls */reading-*html */*/reading-*html |
wc -l`" "`cat */reading-*html */*/reading-*html | wc -l -c`
echo "       diagrams/images:   "  `ls *png *jpg *gif */*png *.*jpg */*gif */*/*png */*/*png */*/*jpg */*/*gif | wc -l`
echo "Course schedule:           " `ls sched schedule.php | wc -l`"  "`cat sched schedule.php | wc -l -c`

echo "Supporting include files: "   `ls *.inc */*/*.inc | wc -l`" "`cat *.inc */*/*.inc | wc -l -c`

echo "CSS style sheet:           " `ls *.css | wc -l`"  "`cat *.css | wc -l -c`
echo "C programs:              "  `ls *.c */*.c */*/*.c | wc -l` `cat *.c */*.c */*/*.c | wc -l -c`
echo "C header files:           "  `ls *.h */*.h */*/*.h | wc -l`" "`cat *.h */*.h */*/*.h | wc -l -c`

