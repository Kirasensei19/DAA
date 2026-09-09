= 2; s <= n; s++) shots[idx++] = s;
    for (int s = n; s >= 2; s--) shots[idx++] = s;

    printf("Shot sequence (%d shots): ", len);
    for (int i = 0; i < len; i++) printf("%d ", shots[i]);
