/* program to read characters until # found,
   count letters,
   and print histogram of counts
*/

#include <stdio.h>
#include <ctype.h>
/* this approach uses a separate variable for the count of each letter */

/* processing updating of variable counter
   precondition:  none
   postcondition:  counter incremented by 1
                   if counter exceeds max_count, max_count updated
*/
void inc_count (int * counter, int * max_count)
{
  (*counter)++;
  if ((*counter) > (*max_count))
      *max_count = *counter;
}

/* program reads character by character, records counts, 
   and prints histogram */
int main ()
  { // declare and initialize counters
    int a_count = 0;
    int b_count = 0;
    int c_count = 0;
    int d_count = 0;
    int e_count = 0;
    int f_count = 0;
    int g_count = 0;
    int h_count = 0;
    int i_count = 0;
    int j_count = 0;
    int k_count = 0;
    int l_count = 0;
    int m_count = 0;
    int n_count = 0;
    int o_count = 0;
    int p_count = 0;
    int q_count = 0;
    int r_count = 0;
    int s_count = 0;
    int t_count = 0;
    int u_count = 0;
    int v_count = 0;
    int w_count = 0;
    int x_count = 0;
    int y_count = 0;
    int z_count = 0;
    
    /* other declarations */
    char ch;  // character read
    int max_count = 0; // maximum of all letter counts
    int i;    // loop index

    /* process input until # read */
    printf ("enter characters on one or more lines, ending with #\n");
    ch = getchar();
    while (ch != '#')
      { //process a character
        // simplify processing by converting upper case to lower case
        ch = tolower (ch);
        switch (ch)
              { 
              case 'a': inc_count (&a_count, &max_count);
                        break;
              case 'b': inc_count (&b_count, &max_count);
                        break;
              case 'c': inc_count (&c_count, &max_count);
                        break;
              case 'd': inc_count (&d_count, &max_count);
                        break;
              case 'e': inc_count (&e_count, &max_count);
                        break;
              case 'f': inc_count (&f_count, &max_count);
                        break;
              case 'g': inc_count (&g_count, &max_count);
                        break;
              case 'h': inc_count (&h_count, &max_count);
                        break;
              case 'i': inc_count (&i_count, &max_count);
                        break;
              case 'j': inc_count (&j_count, &max_count);
                        break;
              case 'k': inc_count (&k_count, &max_count);
                        break;
              case 'l': inc_count (&l_count, &max_count);
                        break;
              case 'm': inc_count (&m_count, &max_count);
                        break;
              case 'n': inc_count (&n_count, &max_count);
                        break;
              case 'o': inc_count (&o_count, &max_count);
                        break;
              case 'p': inc_count (&p_count, &max_count);
                        break;
              case 'q': inc_count (&q_count, &max_count);
                        break;
              case 'r': inc_count (&r_count, &max_count);
                        break;
              case 's': inc_count (&s_count, &max_count);
                        break;
              case 't': inc_count (&t_count, &max_count);
                        break;
              case 'u': inc_count (&u_count, &max_count);
                        break;
              case 'v': inc_count (&v_count, &max_count);
                        break;
              case 'w': inc_count (&w_count, &max_count);
                        break;
              case 'x': inc_count (&x_count, &max_count);
                        break;
              case 'y': inc_count (&y_count, &max_count);
                        break;
              case 'z': inc_count (&z_count, &max_count);
                        break;
              default :  ;// do nothing if a non-letter read
              } // end switch
        ch = getchar ();
      } // end loop for reading
    
    // print histogram
    for (i = max_count; i > 0; i--)
      { // process each letter in turn
        if (a_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (b_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (c_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (d_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (e_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (f_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (g_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (h_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (i_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (j_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (k_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (l_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (m_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (n_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (o_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (p_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (q_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (r_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (s_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (t_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (u_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (v_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (w_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (x_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (y_count >= i)
          printf (" *");
        else
          printf ("  ");
        if (z_count >= i)
          printf (" *");
        else
          printf ("  ");
        printf ("\n");
      } // end printing lines of histogram
    // print scale at bottom of histogram
    for (i = 'a'; i <= 'z'; i++)
      printf (" %c", i);
    printf ("\n");
  }
