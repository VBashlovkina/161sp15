/* program to read characters until # found,
   count letters,
   and print histogram of counts
*/

#include <stdio.h>
#include <ctype.h>
/* this approach uses a separate variable for the count of each letter,
   and combines the counts in an array for the histogram */

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
    int i, j;    // loop indices

    /* process input until # read */
    printf ("enter characters on one or more lines, ending with #\n");
    ch = getchar();
    while (ch != '#')
      { //process letters only
        if (isalpha (ch))
          {  // simplify processing by converting upper case to lower case
             ch = tolower (ch);
             switch (ch)
               { 
                  case 'a': a_count++;
                            break;
                  case 'b': b_count++;
                            break;
                  case 'c': c_count++;
                            break;
                  case 'd': d_count++;
                            break;
                  case 'e': e_count++;
                            break;
                  case 'f': f_count++;
                            break;
                  case 'g': g_count++;
                            break;
                  case 'h': h_count++;
                            break;
                  case 'i': i_count++;
                            break;
                  case 'j': j_count++;
                            break;
                  case 'k': k_count++;
                            break;
                  case 'l': l_count++;
                            break;
                  case 'm': m_count++;
                            break;
                  case 'n': n_count++;
                            break;
                  case 'o': o_count++;
                            break;
                  case 'p': p_count++;
                            break;
                  case 'q': q_count++;
                            break;
                  case 'r': r_count++;
                            break;
                  case 's': s_count++;
                            break;
                  case 't': t_count++;
                            break;
                  case 'u': u_count++;
                            break;
                  case 'v': v_count++;
                            break;
                  case 'w': w_count++;
                            break;
                  case 'x': x_count++;
                            break;
                  case 'y': y_count++;
                            break;
                  case 'z': z_count++;
                            break;
               } // end switch
          } // end isalpha processing
        ch = getchar ();
      } // end loop for reading
    
    // collect counts in an array 
    int count [] = {a_count, b_count, c_count, d_count, e_count, 
                    f_count, g_count, h_count, i_count, j_count, 
                    k_count, l_count, m_count, n_count, o_count, 
                    p_count, q_count, r_count, s_count, t_count, 
                    u_count, v_count, w_count, x_count, y_count, 
                    z_count};

    // find maximum letter count
    max_count = count [0];
    for (i = 1; i < 26; i++)
      if (max_count < count[i])
        max_count = count[i];

    // print histogram
   
   for (i = max_count; i > 0; i--)
      { // process each letter in turn
        for (j = 0; j < 26; j++)
          if (count[j] >= i)
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
