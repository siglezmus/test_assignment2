#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <Windows.h>
#pragma warning(disable:4996)

// Observer class
class Observer {
public:
	void update(std::string data) {
		using namespace std;
		string log_file_path = "log.txt";
		ofstream logFile;
		cout << data << endl;
		logFile.open(log_file_path, std::ios::app);
		if (logFile.is_open()) {
			logFile << data << endl;
		}
		else {
			cout << "Error opening log file" << endl;
		}
		logFile.close();
	}
};

// Device interface
class Device {
public:
	virtual void updateMeasurements() = 0;
	virtual void registerObserver(Observer* observer) = 0;
	virtual void notifyObserver() = 0;
};

// Subject (SpeedSensor) class
class SpeedSensor : Device {

public:
	std::string speed;
	std::string sensor_name;
	Observer* observer;

	SpeedSensor(Observer* observer, std::string sensor_name) {
		this->sensor_name = sensor_name;
		this->registerObserver(observer);
	}

	void registerObserver(Observer* observer) {
		this->observer = observer;
	}

	void notifyObserver() {
		time_t rawtime;
		struct tm* timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
		std::string time_stamp(buffer);
		observer->update(time_stamp + " Sensor " + sensor_name + " sends sensor value:" + speed);
	}

	void updateMeasurements() {
		speed = std::to_string(rand());
		notifyObserver();
	}
};

class AirFlowSensor : Device {

public:
	std::string air_flow_level;
	std::string sensor_name;
	Observer* observer;

	AirFlowSensor(Observer* observer, std::string sensor_name) {
		this->sensor_name = sensor_name;
		this->registerObserver(observer);
	}

	void registerObserver(Observer* observer) {
		this->observer = observer;
	}

	void notifyObserver() {
		time_t rawtime;
		struct tm* timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
		std::string time_stamp(buffer);
		observer->update(time_stamp + " Sensor " + sensor_name + " sends sensor value:" + air_flow_level);
	}

	void updateMeasurements() {
		air_flow_level = std::to_string(rand());
		notifyObserver();
	}
};


int main() {
	srand(time(0));
	// Create observer
	Observer observer;

	// Create sensors
	SpeedSensor speedSensor(&observer, "Speed sensor 1");
	SpeedSensor speedSensor2(&observer, "Speed sensor 2");
	AirFlowSensor airflowSersor(&observer, "Air flow sensor 1");

	// Simulate data updates
	while (true) {
		speedSensor.updateMeasurements();
		speedSensor2.updateMeasurements();
		airflowSersor.updateMeasurements();
		Sleep(5000);
	}

	return 0;
}
