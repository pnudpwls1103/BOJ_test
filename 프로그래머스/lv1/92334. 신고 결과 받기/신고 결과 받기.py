def solution(id_list, report, k):
    check_list = { id : set() for id in id_list }
    
    for element in report:
        _from, to = element.split()
        check_list[_from].add(to)
        
    count_list = { id : 0 for id in id_list }
    for _from in id_list:
        cur = check_list[_from]
        for stop_name in cur:
            count_list[stop_name] += 1

    # check_list : { id : [신고한 사람] }
    # count_list : { id : 신고 횟수}
    # answer     : { id 순으로 메일 횟수 }
    answer = []
    
    for name in id_list:
        mail = 0
        for user in check_list[name]:
            if count_list[user] >= k:
                mail += 1
        answer.append(mail)

    return answer