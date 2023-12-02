- 주차 요금은 누적된 시간으로 계산한다.
- 출차가 없을 경우 23시 59분에 출차된 것으로 계산한다.
- 누적 주차 시간이 기본 시간 이하일경우 기본 요금으로 계산
- 누적 주차 시간이 기본시간 이상일 경우 기본 요금 + ((누적 주차시간 - 기본시간)  / 단위 시간)* 단위 요금으로 계산
```C++
struct ParkingData
{
    bool operator==(const ParkingData& other)
    {
        return (hour == other.hour && min == other.min);
    }

    int hour;
    int min;
};

int GetTime(int hour, int min)
{
    return (hour * 60 + min);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, ParkingData> parkingDatas;      // car Num, Data
    map<string, int> parkingTime;

    for (string record : records)
    {
        pair<string, ParkingData> dataPair;
        ParkingData data;
        string carNum;

        string temp = "";
        int index = 0;
        index = record.find(":");
        temp = record.substr(0, index);
        data.hour = atoi(temp.c_str());
        record.erase(record.begin(), record.begin() + index + 1);

        index = record.find(" ");
        temp = record.substr(0, index);
        data.min = atoi(temp.c_str());
        record.erase(record.begin(), record.begin() + index + 1);

        index = record.find(" ");
        temp = record.substr(0, index);
        carNum = temp;
        record.erase(record.begin(), record.begin() + index + 1);

        string state = record;

        if (state == "IN")                          // 입차
        {
            dataPair.first = carNum;
            dataPair.second = data;
            parkingDatas.insert(dataPair);
        }

        else                                        // 출차
        {
            ParkingData inData = parkingDatas[carNum];

            int intervalTime = data.hour - inData.hour;
            int intervalMin = data.min - inData.min;

            if (parkingTime.count(carNum) == 0)
            {
                pair<string, int> timePair;
                timePair.first = carNum;
                timePair.second = GetTime(intervalTime, intervalMin);

                parkingTime.insert(timePair);
            }

            else
            {
                parkingTime[carNum] += GetTime(intervalTime, intervalMin);
            }

            parkingDatas.erase(carNum);
        }
    }           // 입, 출차 계산

    for (pair<string, ParkingData> leftCar : parkingDatas)
    {
        int intervalTime = 23 - leftCar.second.hour;
        int intervalMin = 59 - leftCar.second.min;

        pair<string, int> timePair;
        timePair.first = leftCar.first;
        timePair.second = GetTime(intervalTime, intervalMin);

        if (parkingTime.count(timePair.first) == 0)
        {
            parkingTime.insert(timePair);
        }

        else
        {
            parkingTime[timePair.first] += timePair.second;
        }
    }           // 출차되지 않고 남은 차 계산

    for (pair<string, int> times : parkingTime)
    {
        if (times.second < fees[0])
            answer.push_back(fees[1]);
        else
        {
            int time = times.second;
            int fee = 0;
            fee = fees[1];
            time -= fees[0];

            int value = time % fees[2] == 0 ? 0 : 1;

            fee += ((time / fees[2]) + value) * fees[3];

            answer.push_back(fee);
        }
    }           // 요금 계산

    return answer;
}
```