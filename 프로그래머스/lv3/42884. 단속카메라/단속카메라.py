def solution(routes):
    data = []
    for i, route in enumerate(routes):
        data.append([route[0], 'IN', i])
        data.append([route[1], 'OUT', i])
    data.sort(key = lambda x : x[0])

    inList = []
    cameraList = []

    for i, route in enumerate(data):
        # IN
        if route[1] == 'IN':
            inList.append(route)
        # OUT
        else:
            inCamera = False
            for j, car in enumerate(inList):
                if(route[2] == car[2]):
                    _in = inList.pop(j)[0]
                    break
            
            for j, camera in enumerate(cameraList):
                if _in <= camera <= route[0]:
                    inCamera = True
                    break
            
            if not inCamera:
                cameraList.append(route[0])
                    
    answer = len(cameraList)
    return answer