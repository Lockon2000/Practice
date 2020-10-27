def get_earliest(*dates):
    earliestDateIndex = 0
    earliestDateMonths, earliestDateDays, earliestDateYears = list(map(int, dates[earliestDateIndex].split("/")))

    def updateEarliest(index):
        nonlocal earliestDateIndex, earliestDateDays, earliestDateMonths, earliestDateYears
        earliestDateIndex = index
        earliestDateMonths, earliestDateDays, earliestDateYears = list(map(int, dates[earliestDateIndex].split("/")))

    for index, date in enumerate(dates[1:], 1):
        months, days, years = list(map(int, date.split("/")))
        if years < earliestDateYears:
            updateEarliest(index)
        elif years == earliestDateYears:
            if months < earliestDateMonths:
                updateEarliest(index)
            elif months == earliestDateMonths:
                if days < earliestDateDays:
                    updateEarliest(index)

    return dates[earliestDateIndex]
