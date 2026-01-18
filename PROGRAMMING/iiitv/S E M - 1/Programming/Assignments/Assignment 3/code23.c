#include <stdio.h>

int main () {
    enum Weekday {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    enum Weekday today;
    today = Wednesday;
    printf ("Monday = %d\n", Monday);
    printf ("Tuesday = %d\n", Tuesday);
    printf ("Wednesday = %d\n", Wednesday);
    printf ("Thursday = %d\n", Thursday);
    printf ("Friday = %d\n", Friday);
    printf ("Saturday = %d\n", Saturday);
    printf ("Sunday = %d\n", Sunday);
    printf ("Today is Wednesday, which has value: %d\n", today);
    return 0;
}
