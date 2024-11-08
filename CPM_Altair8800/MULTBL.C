main()
{
    int i = 1; 

    while (i <= 6) {
        int j = 1;
        while (j <= 6) {
            printf("%d  ", j * i);
            j = j + 1;
        }
        i = i + 1;
    }
}
