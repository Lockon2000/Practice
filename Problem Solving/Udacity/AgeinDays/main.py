import datetime

def convert(str, arr):
	arr[0] = int(str[0]+str[1]+str[2]+str[3])
	arr[1] = int(str[5]+str[6])
	arr[2] = int(str[8]+str[9])

days_in_months = [31,28,31,30,31,30,31,31,30,31,30,31]
leap_year = [1804,1808,1812,1816,1820,1824,1828,1832,1836,1840,1844,1848,1852,1856,1860,1864,1868,1872,1876,1880,1884,1888,1892,1896,1904,1908,1912,1916,1920,1924,1928,1932,1936,1940,1944,1948,1952,1956,1960,1964,1968,1972,1976,1980,1984,1988,1992,1996,2000,2004,2008,2012,2016,2020,2024,2028,2032,2036,2040,2044,2048,2052,2056,2060,2064,2068,2072,2076,2080,2084,2088,2092,2096,2104,2108]

con = True

while con:
	inp = input("Enter your Age in the form (YYYY-MM-DD): ")

	if inp == "x":
		con = False
	
	birth = [0,0,0]  #try without
	date = [0,0,0]

	convert(inp, birth)
	convert(str(datetime.date.today()), date)

	age = 0

	if date[0] - birth[0] == 0:
		for month in range(birth[1], date[1]):
			age += days_in_months[month-1]
		age -= birth[2]
		age += date[2]
	elif date[0] - birth[0] == 1:
		for month in range(birth[1], 13):
			age += days_in_months[month-1]
		age -= birth[2]

		for month in range(1, date[1]):
			age += days_in_months[month-1]
		age += date[2]
	else:
		for month in range(birth[1], 13):
			age += days_in_months[month-1]
		age -= birth[2]

		for year in range(birth[0]+1, date[0]):
			if year in leap_year:
				age += 366
			else:
				age +=365

		for month in range(1, date[1]):
			age += days_in_months[month-1]
		age += date[2]

	print(age)

