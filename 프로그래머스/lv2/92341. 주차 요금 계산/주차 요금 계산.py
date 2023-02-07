from collections import defaultdict
import math

def solution(fees, records):
    btime, bfee, utime, ufee = fees
    
    # 차량번호 : [시간]
    totalTimes = defaultdict(list)
    for record in records:
        time, number, state = record.split(' ')
        totalTimes[number].append(time)
    
    totalTimes = sorted(totalTimes.items())
    
    # 전체 요금 계산
    answer = []
    for key, values in totalTimes:
        if(len(values) % 2 == 1): values.append('23:59')
        
        total = bfee
        totalTime = 0
        for idx in range(0, len(values), 2):
            inTime = values[idx].split(":")
            inTime = int(inTime[0]) * 60 + int(inTime[1])
            outTime = values[idx + 1].split(":")
            outTime = int(outTime[0]) * 60 + int(outTime[1])
            
            totalTime += outTime - inTime
        if(totalTime >= btime):
            total += math.ceil((totalTime - btime) / utime) * ufee
            
        answer.append(total)

    return answer