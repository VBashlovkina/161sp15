/* program to determine parking fee for a downtown lot.
   fees are explained at
      http://www.cs.grinnell.edu/~walker/courses/161.sp14/suppl-prob.shtml#1

   Version 3:  
        challenge:  develop solution without if statements
                    use Boolean expressions which are 1 if true, 0 if false
        use 24-hour clock
        time given in hours
        compute cost from first time in day to last time in day
            if start<end, the fee = cost
            if start>= end, the fee = entire day cost - fee
        organize processing by interval of starting time
           interval 1:  day 1 midnight- 7:00 am
           interval 2:  day 1 7:00 am - 5:00 pm
           interval 3:  day 1 5:00 pm - midnight
       use max, min functions to determine time in each interval
*/

/* pre-conditions:
     start_ampm and end_ampm are each either 'a' or 'p'
     start_hour and end_hour are each between 1 and 12
     start_minutes and end_minutes are each between 0 and 59

   post-condition:
     the fee for the time interval specified is printed
*/

#include <stdio.h>
#include <math.h>

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

  /* ---------- convert to 24-hour clock ---------- */
  /* first put times in 24-hour format */
  start_time = start_hour * (start_hour <= 11)
               + 12.0 * (start_ampm == 'p')
               + start_minute / 60.0;
 
  end_time = end_hour * (end_hour <= 11)
               + 12.0 * (end_ampm == 'p')
               + end_minute / 60.0;

  /* define first_time as earlier of start_time and end_time */
  double first_time = fmin (start_time, end_time);
  /* define last_time as earlier of start_time and end_time */
  double last_time = fmax (start_time, end_time);

  /* organize computation by amount of time in each interval */
  /* find beginning, end, fee in interval 1: midnight- 7:00 am */
  double begin1 = fmin (first_time, 7.0);
  double end1   = fmin (last_time, 7.0);
  double cost1   = (end1 - begin1) * 1.25;

  /* find beginning, end, fee in interval 2: 7:00 am - 5:00 pm */
  double begin2 = fmax (fmin (first_time, 17.0), 7.0);
  double end2   = fmin (fmax (last_time, 7.0), 17.0);
  double cost2   = (end2 - begin2) * 0.75;

  /* find beginning, end, fee in interval 3: 5:00 pm - midnight */
  double begin3 = fmax (first_time, 17.0);
  double end3   = fmax (last_time, 17.0);
  double cost3   = (end3 - begin3) * 2.00;

  /* cost from first_time to end_time */
  double cost = cost1 + cost2 + cost3;

  /* if start_time < end_time, fee = cost */
  double fee = cost * (start_time < end_time)
         /* if start_time >= end_time, fee = full day - cost */
         + ((7*1.25 + 10*0.75 + 7*2.00) - cost)* (start_time >= end_time);

  /* print the total fee */
  printf ("starting hours:  %.2lf\n", start_time);
  printf ("ending hours:    %.2lf\n", end_time);
  printf (" itemized parking fees:\n");
  printf ("    interval 1:  midnight- 7:00 am:  $%5.2lf\n", cost1);
  printf ("    interval 2:  7:00 am - 5:00 pm:  $%5.2lf\n", cost2);
  printf ("    interval 3:  5:00 pm - midnight: $%5.2lf\n", cost3);
  printf ("                           cost sum: $%5.2lf\n", cost);
  printf ("                  parking fee owed:  $%5.2lf\n", fee);

  return 0;
}
