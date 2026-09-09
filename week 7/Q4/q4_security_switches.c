
#include <stdio.h>
#include <stdlib.h>

int sw[70];
int N;
long move_count = 0;

int all_off_beyond(int i) { for (int j = i + 1; j <= N; j++) if (sw[j]) return 0; return 1; }

void toggle(int i) {
    if (i != N) {
        if (!(sw[i + 1] == 1 && all_off_beyond(i + 1))) {
            fprintf(stderr, "ILLEGAL MOVE on switch %d (state violates rule ii)\n", i);
            exit(1);
        }
    }
    sw[i] = !sw[i];
    move_count++;
}

void set_on_front(int lo);
void clear_from_front(int lo);

void set_on_front(int lo) {           /* B(k): all-off -> (ON,0,...,0) */
    if (lo == N) { toggle(N); return; }
    set_on_front(lo + 1);
    toggle(lo);
    clear_from_front(lo + 1);
}

void clear_from_front(int lo) {       /* C(k): (ON,0,...,0) -> all-off */
    if (lo == N) { toggle(N); return; }
    set_on_front(lo + 1);
    toggle(lo);
    clear_from_front(lo + 1);
}

void D_off(int lo) {                  /* D(k): all-on -> all-off */
    if (lo > N) return;               /* empty suffix */
    if (lo == N) { toggle(N); return; }
    D_off(lo + 2);                    /* leaves switch lo+1 ON */
    toggle(lo);
    clear_from_front(lo + 1);
}

long formula(int n) {
    long two_np1 = 1; for (int i = 0; i < n + 1; i++) two_np1 *= 2; /* 2^(n+1) */
    return (n % 2 == 0) ? (two_np1 - 2) / 3 : (two_np1 - 1) / 3;
}

int main(void) {
    printf("Enter number of switches n: ");
    if (scanf("%d", &N) != 1 || N < 1 || N > 30) { fprintf(stderr, "invalid n\n"); return 1; }
    for (int i = 1; i <= N; i++) sw[i] = 1;

    long expected = formula(N);
    D_off(1);

    int all_off = 1;
    for (int i = 1; i <= N; i++) if (sw[i]) all_off = 0;

    printf("All switches off: %s\n", all_off ? "yes" : "NO (bug!)");
    printf("Moves used = %ld, closed-form formula = %ld -> %s\n",
           move_count, expected, (move_count == expected) ? "OK" : "MISMATCH");
    return 0;
}
