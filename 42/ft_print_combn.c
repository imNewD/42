#include <unistd.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

int ft_end(char *tab, int size) {
    int count = 0;
    int index = 0;
    while (index < size) {
        if (tab[index] == '9') count++;
        index++;
    }
    if (count == size) return (1);
    else return (0);
}

void ft_print_combn(int n) {
    char tab[n];
    int index = 0;

    while (index < n) tab[index++] = '0';

    while (!ft_end(tab, n)) {
        index = 0;
        while (index < n - 1 && tab[index] == '0') index++;
        while (index < n) ft_putchar(tab[index++]);
        
        if (!ft_end(tab, n)) {
            tab[n - 1]++;
            if (tab[n - 1] == ':') {
                index = n - 1;
                while (index >= 0 && tab[index] == ':') {
                    tab[index] = '0';
                    index--;
                }
                if (index >= 0) tab[index]++;
            }
            ft_putchar(',');
            ft_putchar(' ');
        }
    }
}

int main() {
    ft_print_combn(3);
    return 0;
}
