#ifndef SRC_ASYNC_H_
#define SRC_ASYNC_H_

#include <string>

class SetPasswordWorker : public Nan::AsyncWorker {
  public:
    SetPasswordWorker(const std::string& service, const std::string& account, const std::string& password,
                      Nan::Callback* callback);

    ~SetPasswordWorker();

    void Execute();

  private:
    const std::string service;
    const std::string account;
    const std::string password;
};

class GetPasswordWorker : public Nan::AsyncWorker {
  public:
    GetPasswordWorker(const std::string& service, const std::string& account, Nan::Callback* callback);

    ~GetPasswordWorker();

    void Execute();
    void HandleOKCallback();

  private:
    const std::string service;
    const std::string account;
    std::string password;
    bool success;
};

class DeletePasswordWorker : public Nan::AsyncWorker {
  public:
    DeletePasswordWorker(const std::string& service, const std::string& account, Nan::Callback* callback);

    ~DeletePasswordWorker();

    void Execute();
    void HandleOKCallback();

  private:
    const std::string service;
    const std::string account;
    bool success;
};

class FindPasswordWorker : public Nan::AsyncWorker {
  public:
    FindPasswordWorker(const std::string& service, Nan::Callback* callback);

    ~FindPasswordWorker();

    void Execute();
    void HandleOKCallback();

  private:
    const std::string service;
    std::string password;
    bool success;
};

#endif  // SRC_ASYNC_H_
