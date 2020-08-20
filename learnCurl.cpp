#include <iostream>
#include <curl/curl.h>
#include <string.h>

using namespace std;
//回调函数  得到响应内容
int write_data(void* buffer, int size, int nmemb, void* userp) {
    std::string* str = dynamic_cast<std::string*>((std::string*)userp);
    str->append((char*)buffer, size * nmemb);
    return nmemb;
}
int upload(string url, string& body, string* response);

int main(int argc, char** argv) {

    std::string body;
    std::string response;

    int status_code = upload("http://127.0.0.1:8000/subjects/", body, &response);
    if (status_code != CURLcode::CURLE_OK) {
        return -1;
    }
    cout << body << endl;
    cout << response << endl;

    return 0;
}

int upload(string url, string& body, string* response)
{
    CURL* curl;
    CURLcode ret;
    curl = curl_easy_init();
    struct curl_httppost* post = NULL;
    struct curl_httppost* last = NULL;


    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, (char*)url.c_str());           //指定url
        
        curl_formadd(&post, &last, CURLFORM_PTRNAME, "name", CURLFORM_PTRCONTENTS, "ggggggg", CURLFORM_END);//form-data key(path) 和 value(device_cover)
        curl_formadd(&post, &last, CURLFORM_PTRNAME, "sex", CURLFORM_PTRCONTENTS, "1", CURLFORM_END);//form-data key(path) 和 value(device_cover)
        curl_formadd(&post, &last, CURLFORM_PTRNAME, "age", CURLFORM_PTRCONTENTS, "666", CURLFORM_END);//form-data key(path) 和 value(device_cover)
        curl_formadd(&post, &last, CURLFORM_PTRNAME, "number", CURLFORM_PTRCONTENTS, "666", CURLFORM_END);//form-data key(path) 和 value(device_cover)
        curl_formadd(&post, &last, CURLFORM_PTRNAME, "file", CURLFORM_FILE, "1.pdf", CURLFORM_FILENAME, "1.pdf", CURLFORM_END);// form-data key(file) "./test.jpg"为文件路径  "hello.jpg" 为文件上传时文件名
        
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, post);                     //构造post参数   
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);          //绑定相应
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)response);        //绑定响应内容的地址

        ret = curl_easy_perform(curl);                          //执行请求
        if (ret == 0) {
            curl_easy_cleanup(curl);
            return 0;
        }
        else {
            return ret;
        }
    }
    else {
        return -1;
    }
}
