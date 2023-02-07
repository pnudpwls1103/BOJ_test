def solution(id_list, report, k):
    temp = { id : False for id in id_list }
    check_list = { id : temp.copy() for id in id_list }
    
    # id : {신고한 id : T/F}
    for element in report:
        _from, to = element.split()
        check_list[_from][to] = True
        
    count_list = { id : 0 for id in id_list }
    for _from in id_list:
        cur = check_list[_from]
        for key, value in cur.items():
            if value: count_list[key] += 1
    
    # 여기 코드 맘에 안들어ㅓㅓㅓㅓ
    answer = { id : 0 for id in id_list }
    for id in id_list:
        if count_list[id] >= k:
            for key, value in check_list.items():
                if value[id]:   answer[key] += 1
    
    answer = list(answer.values())
    
    return answer