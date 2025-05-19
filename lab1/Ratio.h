#pragma once  // більш просте використання для уникнення повторно включення коду

class Ratio
{
private:
	int numerator = 0;
	int denominator = 1;

	static int current_count;  // кількість існуючих об'єктів
	static int total_count;    // загальна кількість створених об'єктів
public:
	Ratio();
	Ratio(int OtherNumerator);
	Ratio(int OtherNumerator, int OtherDenominator);
	~Ratio();
	Ratio(const Ratio& other);
	

	void SetSignRatio();
	void SetNumerator(int OtherNumerator);
	void SetDenominator(int OtherDenominator);

	int GetNumerator() const;
	int GetDenominator() const;
	void ShowRatio() const;

	void ReduceRatio();

	friend Ratio operator+(const Ratio& OtherNumber1, const Ratio& OtherNumber);
	friend Ratio operator-(const Ratio& OtherNumber1, const Ratio& OtherNumber);
	friend Ratio operator*(const Ratio& OtherNumber1, const Ratio& OtherNumber);
	friend Ratio operator/(const Ratio& OtherNumber1, const Ratio& OtherNumber);

	bool operator==(const Ratio& OtherNumber) const;
	bool operator!=(const Ratio& OtherNumber) const;
	bool operator>(const Ratio& OtherNumber) const;
	bool operator<(const Ratio& OtherNumber) const;
	bool operator>=(const Ratio& OtherNumber) const;
	bool operator<=(const Ratio& OtherNumber) const;

	Ratio Pow(const int& Exponentiate);

	int WholePartRatio();
	Ratio ShotgunPartRatio(); // дробова частина

	float ConverInFloat();
	int ConverInInt();

	Ratio operator=(const Ratio& OtherNumber);
    Ratio operator+=(const Ratio& OtherNumber);
	Ratio operator-=(const Ratio& OtherNumber);
	Ratio operator*=(const Ratio& OtherNumber);
	Ratio operator/=(const Ratio& OtherNumber);

	bool IsInt() const;

	const char* ToString() const; // 1
	static Ratio FromString(const char* str); // 2
	static int GetCurrentCount() { return current_count; }// 3 (a)
	static int GetTotalCount() { return total_count; } // 3 (b)
};

