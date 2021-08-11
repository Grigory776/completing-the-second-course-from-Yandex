#include "responses.h"


ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    // ���������� ��� �������
    bool first = true;
    if (r.buses.empty()) {
        os << "No stop";
    }
    else {
        for (const string& bus : r.buses) {
            if (!first) {
                os << " ";
            }
            first = false;
            os << bus;
        }
    }
    return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    // ���������� ��� �������
    bool first = true;
    bool second = true;
    if (r.stops.empty()) {
        os << "No bus";
    }
    else {
        for (const string& stop : r.stops) {
            second = true;
            if (!first) {
                os << endl;
            }
            first = false;
            os << "Stop " << stop << ": ";
            if (r.buses_for_stop.at(stop).buses.size() == 1) {
                os << "no interchange";
            }
            else {
                for (const string& outher_bus : r.buses_for_stop.at(stop).buses) {
                    if (!second) {
                        os << " ";
                    }
                    second = false;
                    if (r.bus != outher_bus) {
                        os << outher_bus;
                    }
                }
            }
        }
    }
    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // ���������� ��� �������
    bool first = true;
    bool second = true;
    if (r.buses.empty()) {
        os << "No buses";
    }
    else {
        for (const auto& bus_item : r.buses) {
            second = true;
            if (!first) {
                os << endl;
            }
            first = false;
            os << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                if (!second) {
                    os << " ";
                }
                second = false;
                os << stop;
            }
        }
    }
    return os;
}