#include <stdio.h>
#include <string.h>

enum Days {
    SUNDAY,     // 0
    MONDAY,     // 1
    TUESDAY,    // 2
    WEDNESDAY,  // 3
    THURSDAY,   // 4
    FRIDAY,     // 5
    SATURDAY    // 6
};

// Enum with explicit values
enum HTTP_Status {
    HTTP_OK = 200,
    HTTP_CREATED = 201,
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_NOT_FOUND = 404,
    HTTP_INTERNAL_ERROR = 500
};

// Enum with mixed assignments
enum Priority {
    LOW,        // 0 (auto)
    MEDIUM,     // 1 (auto)
    HIGH = 5,   // 5 (explicit)
    URGENT,     // 6 (auto continues from 5)
    CRITICAL = 10 // 10 (explicit)
};

// TYPEDEF WITH ENUM

// Using typedef for cleaner code
typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

// Typedef with tag
typedef enum FileMode_ {
    READ_MODE,
    WRITE_MODE,
    APPEND_MODE
} FileMode;

typedef enum {
    TEMP_CELSIUS,
    TEMP_FAHRENHEIT,
    TEMP_KELVIN
} TemperatureUnit;

double convertTemperature(double value, TemperatureUnit from, TemperatureUnit to) {
    if (from == to) return value;
    
    // Convert to Celsius first
    double celsius;
    switch(from) {
        case TEMP_CELSIUS:
            celsius = value;
            break;
        case TEMP_FAHRENHEIT:
            celsius = (value - 32) * 5.0/9.0;
            break;
        case TEMP_KELVIN:
            celsius = value - 273.15;
            break;
    }
    
    // Convert from Celsius to target
    switch(to) {
        case TEMP_CELSIUS:
            return celsius;
        case TEMP_FAHRENHEIT:
            return (celsius * 9.0/5.0) + 32;
        case TEMP_KELVIN:
            return celsius + 273.15;
    }
    return 0; // Should never reach here
}

// ENUM IN STRUCTURES

typedef enum {
    ACTIVE,
    INACTIVE,
    SUSPENDED
} AccountStatus;

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
    AccountStatus status;
} BankAccount;

// ENUM TO STRING FUNCTION

// Helper function to convert enum to string
const char* dayToString(enum Days day) {
    switch(day) {
        case SUNDAY: return "Sunday";
        case MONDAY: return "Monday";
        case TUESDAY: return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY: return "Thursday";
        case FRIDAY: return "Friday";
        case SATURDAY: return "Saturday";
        default: return "Unknown";
    }
}

const char* statusToString(AccountStatus status) {
    static const char* strings[] = {
        "ACTIVE", "INACTIVE", "SUSPENDED"
    };
    return strings[status];
}

// ============================
// MAIN FUNCTION - DEMONSTRATION
// ============================

int main() {
    printf("=== C ENUMS DEMONSTRATION ===\n\n");
    
    // Basic enum usage
    printf("BASIC ENUM USAGE:\n");
    enum Days today = WEDNESDAY;
    printf("Today is: %s (value = %d)\n", dayToString(today), today);
    
    // ToDO: usage of unused emums
