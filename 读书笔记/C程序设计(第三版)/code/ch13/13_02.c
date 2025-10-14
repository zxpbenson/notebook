# include <stdio.h>
# include <stdlib.h>

void main()
{
  FILE *in, *out;
  char ch, infile[10], outfile[10];
  printf("Enter the infile name :\n");
  scanf("%s", infile);
  printf("Enter the outfile name :\n");
  scanf("%s", outfile);
  if((in=fopen(infile, "r")) == NULL)
  {
    printf("can not open infile\n");
    exit(0);
  }
  if((in=fopen(outfile, "w")) == NULL)
  {
    printf("can not open outfile\n");
    exit(0);
  }
  while(!feof(in))fputc(fgetc(in), out);
  fclose(in);
  fclose(out);
}