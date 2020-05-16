#pragma once

template<class T>
class SingleInstance {
private:
	static std::once_flag SingletonFlag;
	static std::unique_ptr<T> Instance;

protected:
	SingleInstance() = default;
	SingleInstance(const T&) = delete;
	SingleInstance& operator=(const T&) = delete;

public:
	static T& GetInstance() {
		std::call_once(SingletonFlag, [=]() {
			Instance.reset(new T);
			});

		return *(Instance.get());
	}
};

template <class T> std::unique_ptr<T> SingleInstance <T>::Instance = nullptr;
template <class T> std::once_flag SingleInstance <T>::SingletonFlag;