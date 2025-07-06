/*  Unit Converter
    This program allows a user to convert between different units such as
    inches ↔ centimeters and pounds ↔ kilograms using a simple CLI menu.
*/

#include <stdio.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_CONVERSIONS 20

typedef struct {
  const char* category;
  const char* label;
  const char* from_unit;
  const char* to_unit;
  double (*convert)(double);
} ConversionProfile;

double inches_to_centimeters(double a);
double centimeters_to_inches(double a);
double pounds_to_kilograms(double a);
double kilograms_to_pounds(double a);
double fahrenheit_to_celsius(double a);
double celsius_to_fahrenheit(double a);
int is_unique(const char *category, const char **existing, int count);
int get_unique_categories(const ConversionProfile *conversions, int num_of_conversions, const char **out_categories, int max_categories);
int find_category_indices(const ConversionProfile *conversions, int num_of_conversions, const char *category, int *out_indices, int max_matches);

int is_unique(const char *category, const char **existing, int count) {
  for (int i = 0; i < count; i++) {
    if (strcmp(category, existing[i]) == 0) {
      return 0;
    }
  }
  return 1;
}

int get_unique_categories(const ConversionProfile *conversions, int num_of_conversions, const char **out_categories, int max_categories) {
  int count = 0;

  for (int i = 0; i < num_of_conversions && count < max_categories; i++) {
    const char *cat = conversions[i].category;
    if (is_unique(cat, out_categories, count)) {
      out_categories[count++] = cat;
    }
  }

  return count;
}

int find_category_indices(const ConversionProfile *conversions, int num_of_conversions, const char *category, int *out_indices, int max_matches) {
  int count = 0;
  
  for (int i = 0; i < num_of_conversions && count < max_matches; i++) {
    if (strcmp(conversions[i].category, category) == 0) {
      out_indices[count++] = i;
    }
  }

  return count;
}

int get_user_choice() {
  int choice;
  printf("Choice: ");
  if (scanf("%d", &choice) != 1) {
    // Clear invalid input from stdin
    while (getchar() != '\n') {
      return -1;
    }
  }
  return choice;
}

int main() {
  ConversionProfile conversions[] = {
    {"Distance", "Inches to Centimeters", "in", "cm", inches_to_centimeters},
    {"Distance", "Centimeters to Inches", "cm", "in", centimeters_to_inches},
    {"Mass", "Pounds to Kilograms", "lb", "kg", pounds_to_kilograms},
    {"Mass", "Kilograms to Pounds", "kg", "lb", kilograms_to_pounds},
    {"Temperature", "Fahrenheit to Celsius", "F", "C", fahrenheit_to_celsius},
    {"Temperature", "Celsius to Fahrenheit", "C", "F", celsius_to_fahrenheit}};

  int num_of_conversions = sizeof(conversions) / sizeof(conversions[0]);

  const char *categories[MAX_CATEGORIES];
  int num_categories = get_unique_categories(conversions, num_of_conversions, categories, MAX_CATEGORIES);

  while (1) {
    // Step 1: Category selection
    printf("Which category of measurement would you like to convert?\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d) %s\n", i + 1, categories[i]);
    }
    printf("%d) Exit\n", num_categories + 1);
    int category_choice = get_user_choice();
    if (category_choice == num_categories + 1) break;
    if (category_choice < 1 || category_choice > num_categories) {
        printf("Invalid category. Try again.\n");
        continue;
    }
    // Step 2: Conversion selection
    int conversion_indices[MAX_CONVERSIONS];
    int num_matches = find_category_indices(
        conversions,
        num_of_conversions,
        categories[category_choice - 1],
        conversion_indices,
        MAX_CONVERSIONS
    );
    while (1) {
        printf("\nSelect a conversion:\n");
        for (int j = 0; j < num_matches; j++) {
            int idx = conversion_indices[j];
            printf("%d) %s (%s -> %s)\n", j + 1,
                conversions[idx].label,
                conversions[idx].from_unit,
                conversions[idx].to_unit);
        }
        printf("%d) Back to Categories\n", num_matches + 1);
        int conversion_choice = get_user_choice();
        if (conversion_choice == num_matches + 1) break;
        if (conversion_choice < 1 || conversion_choice > num_matches) {
            printf("Invalid conversion. Try again.\n");
            continue;
        }
        // Step 3: Perform conversion
        double input;
        printf("Enter a value in %s: ", conversions[conversion_indices[conversion_choice - 1]].from_unit);
        scanf("%lf", &input);
        double result = conversions[conversion_indices[conversion_choice - 1]].convert(input);
        printf("Result: %.2f %s\n", result, conversions[conversion_indices[conversion_choice - 1]].to_unit);
    }
    }

    printf("Goodbye!\n");
    return 0;
}

double inches_to_centimeters(double a) {
  return a * 2.54;
}

double centimeters_to_inches(double a) {
  return a / 2.54;
}

double pounds_to_kilograms(double a) {
  return a * 0.453592;
}

double kilograms_to_pounds(double a) {
  return a / 0.453592;
}

double fahrenheit_to_celsius(double a) {
  return (a - 32) * 5.0 / 9.0;
}

double celsius_to_fahrenheit(double a) {
  return a * 9.0 / 5.0 + 32;
}
