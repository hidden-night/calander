#ifndef CALANDER_H_BY_NIGHT
#define CALANDER_H_BY_NIGHT

class Calander
{
	private:
		static inline const int n_months[]{31,28,31,30,31,30,31,31,30,31,30,31};

		bool leap_year(const int& year) const;
		int odd_days();
		bool check_date();

		int m_date[3]{};
		bool m_valid{};
		int m_odd_days{};
	public:
		Calander (int day,int month,int year);
		bool valid() const;
		void print() const;
};

#endif
