#include <stdio.h>

/** 
 * distance - measured in miles
 * time     - measured in minutes
 */
struct trip {
    double distance;
    double time;
};

/**
 * Given an array of struct trip instances, calculates the average speeds of all
 * the trips in miles per hour and stores them in the array speeds.
 */
void calculate_speeds(const struct trip trips[], double speeds[],
                      size_t trip_count);

/**
 * Given a struct trip instance, calculates and returns the average speed in
 * miles per hour.
 */
double calculate_speed(struct trip trip);

/**
 * Given an array of speeds in miles per hour, prints the speed of each trip.
 */
void print_speeds(const double speeds[], size_t trip_count);

int main() {
    printf("How many trips would you like to enter? ");
    size_t trip_count;
    scanf("%zu", &trip_count);

    struct trip trips[trip_count];

    for (size_t i = 0; i < trip_count; i++) {
        printf("Enter the distance in miles for this trip: ");
        scanf("%lf", &trips[i].distance);

        printf("Enter the time in minutes for this trip: ");
        scanf("%lf", &trips[i].time);
    }

    double speeds[trip_count];

    calculate_speeds(trips, speeds, trip_count);

    print_speeds(speeds, trip_count);

    return 0;
}

void print_speeds(const double speeds[], size_t trip_count) {
    printf("Average speeds:\n");
    for (size_t i = 0; i < trip_count; i++) {
        printf("Trip %zu: %.2lf mi/h\n", i + 1, speeds[i]);
    }
}

double calculate_speed(struct trip trip) {
    double speed = trip.distance / trip.time * 60;
    return speed;
}

void calculate_speeds(const struct trip trips[], double speeds[],
                      size_t trip_count) {
    for (size_t i = 0; i < trip_count; i++) {
        speeds[i] = calculate_speed(trips[i]);
    }
}
