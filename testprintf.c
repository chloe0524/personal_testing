#include <stdio.h>
#include <stdarg.h>

typedef struct {
	char specifier;
	void (handler)(va_list);
} ConversionHandler;

void handle_char(va_list args) {
	putchar(va_arg(args, int));
}

void handle_string(va_list args) {
	const charstr = va_arg(args, const char );
	while (str != '\0') {
		putchar(str);
		str++;
	}
}

void handle_percent(va_list args) {
	putchar('%');
}

int _printf(const charformat, ...) {
	va_list args;
	va_start(args, format);

	int count = 0;  // Pour suivre le nombre de caractères imprimés

	while (format != '\0') {
		if (format == '%') {
			format++;  // Passer le '%'

			ConversionHandler handlers[] = {
				{'c', handle_char},
				{'s', handle_string},
				{'%', handle_percent},
				// Ajoutez d'autres spécificateurs de conversion au besoin
			};

			for (int i = 0; i < sizeof(handlers) / sizeof(handlers[0]); i++) {
				if (format == handlers[i].specifier) {
					handlers[i].handler(args);
					count++;
					break;
				}
			}
		} else {
			putchar(format);
			count++;
		}

		format++;  // Passer au caractère suivant dans la chaîne de format
	}

	va_end(args);
	return count;
}

int main() {
	// Exemple d'utilisation
	int chars_printed = _printf("Bonjour, %c! C'est un exemple %s : %%printf\n", 'W', "simple");
	printf("\nNombre de caractères imprimés : %d\n", chars_printed);

	return 0;
}
