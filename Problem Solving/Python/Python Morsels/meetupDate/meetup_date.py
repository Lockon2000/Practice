import datetime
from calendar import monthrange

def meetup_date(year, month, nth=4, weekday=3):
    if nth > 0:
        firstWeekdayInMonth = 1 + (-(datetime.date(year, month, 1).weekday() - weekday) % 7)
        return datetime.date(year, month, firstWeekdayInMonth + (nth - 1)*7)
    elif nth < 0:
        nth = -nth
        lastday = monthrange(year, month)[1]
        lastWeekdayInMonth = lastday - ((datetime.date(year, month, lastday).weekday() - weekday) % 7)
        return datetime.date(year, month, lastWeekdayInMonth - (nth - 1)*7)

