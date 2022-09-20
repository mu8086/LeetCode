int * corpFlightBookings(int **bookings, int bookingsSize, int *bookingsColSize, int n, int *returnSize) {
    int *ret = (int *) malloc(sizeof(int) * (n+1));
    memset(ret, 0, sizeof(int) * (n+1));

    for (int i = 0, first, after, seats; i < bookingsSize; ++i) {
        first = bookings[i][0]-1;
        after = bookings[i][1];
        seats = bookings[i][2];

        ret[first]  += seats;
        ret[after]  -= seats;
    }

    for (int i = 0, carry = 0; i < n; ++i) {
        carry += ret[i];
        ret[i] = carry;
    }

    *returnSize = n;
    return ret;
}
