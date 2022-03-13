#ifndef calander_h_by_night
#define calander_h_by_night

class Calander
{
	private:
		static inline const int dec_31_1950{1950};
		static inline const int n_months[]{31,28,31,30,31,30,31,31,30,31,30,31};
		static inline const int l_months[]{31,29,31,30,31,30,31,31,30,31,30,31};

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
