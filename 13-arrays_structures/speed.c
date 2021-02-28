#include <stdio.h>

/**
 * Given an array of distances in miles and an array of times in minutes,
 * calculates the average speeds of all the trips in miles per hour and
 * stores them in the array speeds.
 */
void calculate_speeds(const double distances[], const double times[], 
                        double speeds[], size_t trip_count);

/**
 * Given a distance in miles and a time in minutes, calculates and returns
 * the average speed in miles per hour.
 */
double calculate_speed(double distance, double time);

/**
 * Given an array of speeds in miles per hour, prints the speed of each trip.
 */
void print_speeds(const double speeds[], size_t trip_count);

int main() {
    size_t trip_count = 5;

    double distances[] = {34.2, 156.8, 239.6, 3.1, 1698.4};
    double times[] = {50.5, 130.25, 220.75, 8.5, 1513.75};

    double speeds[5];
    calculate_speeds(distances, times, speeds, trip_count);

    print_speeds(speeds, trip_count);

    return 0;
}

void print_speeds(const double speeds[], size_t trip_count) {
    printf("Average speeds:\n");
    for (size_t i = 0; i < trip_count; i++) {
        printf("Trip %zu: %.2lf mi/h\n", i + 1, speeds[i]);
    }
}

double calculate_speed(double distance, double time) {
    double speed = distance / time * 60;
    return speed;
}

void calculate_speeds(const double distances[], const double times[],
                      double speeds[], size_t trip_count) {
    for (size_t i = 0; i < trip_count; i++) {
        speeds[i] = calculate_speed(distances[i], times[i]);
    }
}
