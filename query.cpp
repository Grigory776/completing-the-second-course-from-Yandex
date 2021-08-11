#include "query.h"

istream& operator >> (istream& is, Query& q) {
    // Реализуйте эту функцию
    size_t stop_count;
    string type, bus, stop;
    is >> type;
    if (type == "NEW_BUS") {
        is >> bus >> stop_count;
        vector<string> stops(stop_count);
        for (string& stop_name : stops) {
            is >> stop_name;
        }
        q.type = QueryType::NewBus;
        q.bus = bus;
        q.stops = stops;
    }
    else if (type == "BUSES_FOR_STOP") {
        is >> stop;
        q.type = QueryType::BusesForStop;
        q.stop = stop;
    }
    else if (type == "STOPS_FOR_BUS") {
        is >> bus;
        q.type = QueryType::StopsForBus;
        q.bus = bus;
    }
    else if (type == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }

    return is;
}