/* program to encrypt a message with a simple polyalphabetic cipher 

   one basic cipher alphabet is used.  
   a keyword is used to shift a plain text letter, before it is
    replaced with a character from the cipher alphabet.

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt_message (char cipherAlpha [], char keyword [],
                      char message [], char encrypted [])
{
  int k;
  for (k = 0; k < strlen(message); k++)
    {
      if (isalpha (message[k]))
        {
          /* plain alphabet position 0..25 */
          int plainPos = message[k] - 'A';
          /* keyword position 0..strlen(keyword)-1 */
          int keywordPos = keyword [k%strlen(keyword)] - 'A';
          /* shifted position in plain alphabet */
          int shiftedPos = (plainPos + keywordPos) % 26;
          /* store letter in cipher alphabet */
          encrypted [k] = cipherAlpha [shiftedPos];
        }
      else
        encrypted [k] = message [k];
    }
  encrypted [strlen(message)] = 0;
}

void decrypt_message (char cipherAlpha [], char keyword [],
                      char encrypted [], char decrypted [])
{
  int k;
  for (k = 0; k < strlen(encrypted); k++)
    {
      if (isalpha (encrypted[k]))
        {
          /* look up character in cipher alphabet */
          int cipherPos = 0;
          while ((cipherPos < 26) && (encrypted [k] != cipherAlpha [cipherPos]))
            cipherPos++;
          /* keyword position 0..strlen(keyword)-1 */
          int keywordPos = keyword [k%strlen(keyword)] - 'A';
          /* store letter in cipher alphabet */
          decrypted [k] = ((26 + cipherPos - keywordPos) % 26) + 'A';
        }
      else
        decrypted [k] = encrypted [k];
    }
  decrypted [strlen(encrypted)] = 0;
}


int main ()
{
  /* cipherAlpha leaves room for alphabet, return in read, and null */
  char cipherAlpha [28] = "XDQTVBKRAUGMZHYWCJOSENILPF";
  int keyword_max = 80;
  char keyword [keyword_max];
  int max = 80;
  char message [max];
  char encrypted [max];
  char decrypted [max];
  int i;

  printf ("%d %d\n", -27%26, -25%26);

  printf ("program to encode via a keyword-based polyalphabetic cipher\n");
  printf ("   all characters are converted to upper case for simplicity\n");

  printf ("       plain alphabet:  ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
  printf ("enter cipher alphabet:  ");
  fgets (cipherAlpha, 28, stdin);
  printf ("cipher alphabet: %s\n", cipherAlpha);

  printf ("enter keyword:  ");
  fgets (keyword, keyword_max, stdin);
  for (i = 0; i < strlen(keyword); i++)
    keyword [i] = toupper(keyword [i]);
  /* remove line feed at end of keyword */
  if (!isalpha(keyword[strlen(keyword)-1]))
    keyword[strlen(keyword)-1] = 0;

  /* read message */
  printf ("enter message:\n");
  fgets (message, max, stdin);
  for (i = 0; i < strlen(message); i++)
    message [i] = toupper (message [i]);

  /* encode text */
  encrypt_message (cipherAlpha, keyword, message, encrypted);
  printf ("encrypted message is\n   %s\n", encrypted);

  /* encode text */
  decrypt_message (cipherAlpha, keyword, encrypted, decrypted);
  printf ("decrypted message is\n   %s\n", decrypted);

  return 0;
}
