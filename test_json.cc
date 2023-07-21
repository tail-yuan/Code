#include <iostream>
#include <jsoncpp/json/json.h>
using namespace std;

int main()
{
    Json::Value jsonData;
    jsonData["name"] = "yuanwei";
    jsonData["age"] = "21";
    jsonData["city"] = "shenyang";
    jsonData["language"] = "C++";
    Json::FastWriter writer1;
    string jsonString1 = writer1.write(jsonData);
    cout << "Serilazible string# " << jsonString1 << endl;

    Json::StreamWriterBuilder writer2;
    string jsonString2 = Json::writeString(writer2, jsonData);
    cout << "Serilazible string# " << jsonString2 << endl;

    Json::StyledWriter writer3;
    string jsonString3 = writer3.write(jsonData);
    cout << "Serilazible string# " << jsonString3 << endl;

    // 反序列化FastWriter StyledWriter
    cout << "反序列化" << endl;
    Json::Value parseData;
    Json::Reader reader;
    if (!reader.parse(jsonString3, parseData))
    {
        cout << "Error parse" << endl;
        return 1;
    }
    std::string name = parseData["name"].asString();
    std::string age = parseData["age"].asString();
    std::string city = parseData["city"].asString();
    std::string language = parseData["language"].asString();

    cout << name << " " << age << " " << city << " " << language << endl;
    return 0;
}