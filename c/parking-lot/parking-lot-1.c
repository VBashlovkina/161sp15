/* program to determine parking fee for a downtown lot.
   fees are explained at
      http://www.cs.grinnell.edu/~walker/courses/161.sp14/suppl-prob.shtml#1

   Version 1:  
        use 48-hour clock
        time given in minutes
        organize processing by day intervals
           interval 1:  day 1 midnight- 7:00 am
           interval 2:  day 1 7:00 am - 5:00 pm
           interval 3:  day 1 5:00 pm - midnight
           interval 4:  day 2 midnight- 7:00 am
           interval 5:  day 2 7:00 am - 5:00 pm
           interval 6:  day 2 5:00 pm - midnight
        note: car parked for <= 24 hours, so car's time spans <= 4 intervals
*/

/* pre-conditions:
     start_ampm and end_ampm are each either 'a' or 'p'
     start_hour and end_hour are each between 1 and 12
     start_minutes and end_minutes are each between 0 and 59

   post-condition:
     the fee for the time interval specified is printed
*/

#include <stdio.h>

int main ()
{
  /* user-entered times */
  int start_hour = 12;
  int start_minute = 0;
  int start_ampm = 'a';
  int end_hour = 12;
  int end_minute = 0;
  int end_ampm = 'a';

  int start_time, end_time;

  /* ---------- convert to 48-hour clock ---------- */
  /* first put times in 24-hour (24*60)-minute format */
  if (start_hour == 12)
    {  
      if (start_ampm == 'a')
        start_time = start_minute;  /* day starts at 0:00*/
      else 
        start_time = 12*60 + start_minute;  /* minutes after noon */
    }
  else if (start_ampm == 'a')
 
    start_time = start_hour * 60 + start_minute;
  else
    start_time = start_hour * 60 + start_minute + 12*60;

  if (end_hour == 12)
    {  
      if (end_ampm == 'a')
        end_time = end_minute;  /* day starts at 0:00*/
      else 
        end_time = 12*60 + end_minute;  /* minutes after noon */
    }
  else if (end_ampm == 'a')
    end_time = end_hour * 60 + end_minute;
  else
    end_time = end_hour * 60 + end_minute + 12*60;

  /* if end_time <= start_time, end must be in next day */
  if (end_time <= start_time)
    end_time += 24*60;

  /* determine fees charged in each time interval */
  double fee1 = 0.0;
  double fee2 = 0.0;
  double fee3 = 0.0;
  double fee4 = 0.0;
  double fee5 = 0.0;
  double fee6 = 0.0;

  /* compute fee for interval 1:  day 1 midnight- 7:00 am  */
  /* 7:00 am corresponds to 7*60 = 420 minutes */
  if (start_time < 420)
    {
      double first_minute_rate = 1.25 / 60.0;
      if (end_time < 420)
        fee1 = (end_time - start_time) * first_minute_rate;
      else /* 1.25 rate applies only until end of this interval */
        fee1 = (420 - start_time) * first_minute_rate;
    }

  /* compute fee for interval 2:  day 1 7:00 am - 5:00 pm  */
  /* 7:00 am corresponds to  7*60 =  420 minutes
     5:00 pm corresponds to 17*60 = 1020 minutes */
  if (start_time < 1020 && end_time > 420)
    { double second_minute_rate = 0.75 / 60.0;
      double interval_start = start_time;
      double interval_end = end_time;
      if (start_time < 420)
        interval_start = 420;
     
      if (end_time > 1020)
        interval_end = 1020;

      fee2 = (interval_end - interval_start) * second_minute_rate;
    }

  /* compute fee for interval 3:  day 1 5:00 pm - midnight */
  /* 5:00 pm corresponds to 17*60 = 1020 minutes 
     midnight corresponds to 24*60 = 1440 minutes */
  if (start_time < 1440 && end_time > 1020)
    { double third_minute_rate = 2.00 / 60.0;
      double interval_start = start_time;
      double interval_end = end_time;;
      if (start_time < 1020)
        interval_start = 1020;
     
      if (end_time > 1440)
        interval_end = 1440;

      fee3 = (interval_end - interval_start) * third_minute_rate;
    }

  /* compute fee for interval 4:  day 2 midnight- 7:00 am  */
  /* midnight corresponds to 24*60 = 1440 minutes 
     7:00 am  corresponds to 1440 + 7*60 = 1860 minutes */
  if (start_time < 1860 && end_time > 1440)
    { double fourth_minute_rate = 1.25 / 60.0;
      double interval_start = start_time;
      double interval_end = end_time;;
      if (start_time < 1440)
        interval_start = 1440;
     
      if (end_time > 1860)
        interval_end = 1860;

      fee4 = (interval_end - interval_start) * fourth_minute_rate;
    }

  /* compute fee for interval 5:  day 2 7:00 am - 5:00 pm  */
  /* 7:00 am  corresponds to 1440 +  4*60 = 1860 minutes
     5:00 pm  corresponds to 1440 + 17*60 = 2460 minutes */

  if (start_time < 2460 && end_time > 1860)
    { double fifth_minute_rate = 0.75 / 60.0;
      double interval_start = start_time;
      double interval_end = end_time;;
      if (start_time < 1860)
        interval_start = 1860;
     
      if (end_time > 2460)
        interval_end = 2460;

      fee5 = (interval_end - interval_start) * fifth_minute_rate;
    }

  /* compute fee for interval 6:  day 2 5:00 pm - midnight */
  /* 5:00 pm  corresponds to 1440 + 17*60 = 2460 minutes
     midnight corresponds to 1440 + 1440 = 2880 minutes */
  if (end_time > 2460)
    { double sixth_minute_rate = 2.00 / 60.0;
      double interval_start = start_time;
      double interval_end = end_time;;
      if (start_time < 2460)
        interval_start = 2460;
     
      fee6 = (interval_end - interval_start) * sixth_minute_rate;
    }

  /* print fees for each interval and for the total */
  double total_owed = fee1 + fee2 + fee3 + fee4 + fee5 + fee6;
  printf ("starting hours:  %.2lf\n", start_time/60.0);
  printf ("ending hours:    %.2lf\n", end_time/60.0);

  printf (" itemized parking fees:\n");
  printf ("    interval 1:  day 1 midnight- 7:00 am:  $%5.2lf\n", fee1);
  printf ("    interval 2:  day 1 7:00 am - 5:00 pm:  $%5.2lf\n", fee2);
  printf ("    interval 3:  day 1 5:00 pm - midnight: $%5.2lf\n", fee3);
  printf ("    interval 4:  day 2 midnight- 7:00 am:  $%5.2lf\n", fee4);
  printf ("    interval 5:  day 2 7:00 am - 5:00 pm:  $%5.2lf\n", fee5);
  printf ("    interval 6:  day 2 5:00 pm - midnight: $%5.2lf\n", fee6);

  printf ("                  total parking fee owed:  $%5.2lf\n", 
          total_owed);

  return 0;
}
