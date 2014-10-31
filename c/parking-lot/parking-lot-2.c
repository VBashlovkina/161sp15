/* program to determine parking fee for a downtown lot.
   fees are explained at
      http://www.cs.grinnell.edu/~walker/courses/161.sp14/suppl-prob.shtml#1

   Version 2:  
        use 24-hour clock
        time given in hours
        organize processing by interval of starting time
           interval 1:  day 1 midnight- 7:00 am
           interval 2:  day 1 7:00 am - 5:00 pm
           interval 3:  day 1 5:00 pm - midnight
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

  double start_time, end_time;

  /* hourly rates for different times of day */
  const double early_rate = 1.25;
  const double day_rate = 0.75;
  const double evening_rate = 2.00;

  /* ---------- convert to 48-hour clock ---------- */
  /* first put times in 24-hour format */
  if (start_hour == 12)
    {  
      if (start_ampm == 'a')
        start_time = start_minute/60.0 ;  /* day starts at 0:00*/
      else 
        start_time = 12.0 + start_minute/60.0 ;  /* hours after noon */
    }
  else if (start_ampm == 'a')
 
    start_time = start_hour + start_minute/60.0;
  else
    start_time = start_hour + start_minute/60.0 + 12.0;

  if (end_hour == 12)
    {  
      if (end_ampm == 'a')
        end_time = end_minute/60.0 ;  /* day starts at 0:00*/
      else 
        end_time = 12 + end_minute/60.0 ;  /* hours after noon */
    }
  else if (end_ampm == 'a')
    end_time = end_hour + end_minute/60.0 ;
  else
    end_time = end_hour + end_minute/60.0 + 12.0;

   /* determine fee charged */
  double fee;

  /* start time in midnight - 7:00 am  */
  if (start_time < 7.0)
    {
      if (end_time <= 7.0)
        {
          if (end_time <= start_time)
            /* start one day, end next, spanning 4 time intervals */
            fee = (7.0 - start_time) * early_rate
                  + 10.0 * day_rate
                  + 7.0 * evening_rate
                  + end_time * early_rate;
          else /* all time in early interval, spanning 1 time interval */
            fee = (end_time -start_time) * early_rate;
        }
      else if (end_time < 17.0)
        /* start early, finish during day, spanning 2 time intervals */
            fee = (7.0 - start_time) * early_rate
                  + (end_time - 7.0) * day_rate;
      else /* start early, finish in evening, spanning 3 time intervals */
           fee = (7.0 - start_time) * early_rate
                  + 10.0 * day_rate
                  + (end_time - 17.0) * evening_rate;
    }

  /* start time in 7:00 am - 5:00 pm  */
  else if (start_time < 17.0)
    { 
      if (end_time <= 7.0)
        /* start one day, end next, spanning 3 time intervals */
        fee = (17.0 - start_time) * day_rate
              + 7.0 * evening_rate
              + end_time * early_rate;
      else if (end_time <= 17.0)
             { /* start and end during daytime */
               if (end_time <= start_time)
                 /* start one day, end next, spanning 4 time intervals */
                  fee = (17.0 - start_time) * day_rate
                        + 7.0 * evening_rate
                        + 7.0 * early_rate
                        + (end_time - 7.0) * day_rate;
               else /* start and end during single day */
                 fee = (end_time - start_time) * day_rate;
             }
      else /* start during day, finish in evening, spanning 2 time interval */
        fee = (17.0 - start_time) * day_rate
              + (end_time - 17.0) * evening_rate;
    }

  /* start time in 5:00 pm - midnight */
  else 
    { 
       if (end_time <= 7.0)
         /* start one day, end next, spanning 2 time intervals */
         fee = (24.0 - start_time) * evening_rate
               + end_time * early_rate;
       else if (end_time <= 17.0)
         /* start one day, end next, spanning 3 time intervals */
         fee = (24.0 - start_time) * evening_rate
               + 7.0 * early_rate
               + (end_time - 7.0) * day_rate;
       else /* start and end in evening */
         {
           if (end_time <= start_time)
             /* start one evening, end next, spanning 4 time intervals */
             fee = (24.0 - start_time) * evening_rate
                   + 7.0 * early_rate
                   + 10.0 * day_rate
                   + (end_time - 17.0) * evening_rate;
           else /* start and end during single evening */
                 fee = (end_time - start_time) * evening_rate;
             }
    }

  /* print the total fee */
  printf ("starting hours:  %.2lf\n", start_time);
  printf ("ending hours:    %.2lf\n", end_time);
  printf ("total parking fee owed:  $%5.2lf\n", fee);

  return 0;
}
