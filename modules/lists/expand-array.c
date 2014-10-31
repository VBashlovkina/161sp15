


int main ()
{
  int sizeOfArray = 5;
  int numPics = 0;
  (Picture *) *picArray = malloc (sizeOfArray * sizeof (Picture *));

  int i;
  for (i = 0; i < 20; i++)
    {
      if (numPics >= sizeOfArray)
        {
          Picture* * newSpace = malloc (2*sizeOfArray * sizeof (Picture *));
          int j;
          for (j = 0; j < sizeOfArray)
            newSpace[j] = picArray[j];
          free (picArray);
          picArray = newSpace;
          sizeOfArray *= 2;
        }
      picArray[numPics] = rTakePicture();
      numPics++;
    }
}
