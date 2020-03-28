#! /usr/bin/env python3
# coding=utf-8

import requests
import time


# 语音识别 （语音转文字）
def ASRTxt():
    #url = 'http://bbs.ziyoujie.com:8888'
    url = 'http://localhost:8888'
    #url = 'http://47.110.142.112:8888'
    soundPath = "/home/louj/disk/m2_2T/VoxCeleb1/data/vox1/test/wav/id90148/EEEEEEEE48/76256_39.wav"
    AppID = "24a42z534"
    APIKey = "378d4582ad3ed253057cafe9c70fae8b"
    SecretKey = "d6uk5fd"
    starttime = time.time()
    # 'Language': 'en'
    data = {'AppID': AppID, 'APIKey': APIKey, 'SecretKey': SecretKey,
            'Language': 'cn',
            'SpkTxt': '他完全将自己当成了一个凡人在体会这人世间的生老病死悲欢离合'}
    files = {'Sound': open(soundPath, 'rb')}
    r = requests.post(url, files=files, data=data)
    print(r.url)
    print(str(r.json()))
    print(time.time()-starttime, "秒")


if __name__ == "__main__":
    ASRTxt()


