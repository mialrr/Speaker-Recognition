#! /usr/bin/env python3
# coding=utf-8

import requests
import time


# 1:1 检测两个声音是不是同一个人的声音
def Speaker_1_1():
    # url = 'http://bbs.ziyoujie.com:8888'
    url = 'http://localhost:8888'
    #url = 'http://47.110.142.112:8888'
    sound0path = "../sample-files/156_0.wav"
    sound1path = "../sample-files/156_1.wav"
    AppID = "2rtg2z53r"
    APIKey = "378d4582ad3ed253057cafe9c70fae8b"
    SecretKey = "d6uk5fd"
    starttime = time.time()
    data = {'AppID': AppID, 'APIKey': APIKey, 'SecretKey': SecretKey}
    files = {'Sound0': open(sound0path, 'rb'), 'Sound1': open(sound1path, 'rb')}
    r = requests.post(url, files=files, data=data)
    print(r.url)
    print(r.json())
    print(time.time()-starttime, "秒")


# 认证分为两部分（1:检测是否说了指定的文字的语音 2:检测是不是同一个人的声纹）
def ASR_Speaker_1_1():
    # url = 'http://bbs.ziyoujie.com:8888'
    url = 'http://localhost:8888'
    # url = 'http://47.110.142.112:8888'
    sound0path = "../sample-files/76256_39.wav"
    sound1path = "../sample-files/156_1.wav"
    AppID = "2rf9j453r"
    APIKey = "378d4582ad3ed253057cafe9c70fae8b"
    SecretKey = "d6uk5fd"
    starttime = time.time()
    # SpkTxt 对应的是 Sound0
    # 如果是英文语音需要选择 en, 该选项是针对语音识别, 声纹没有Language限制
    data = {'AppID': AppID, 'APIKey': APIKey, 'SecretKey': SecretKey,
            'Language': 'cn',
            'SpkTxt': '他完全将自己当成了一个凡人在体会这人世间的生老病死悲欢离合'}
    files = {'Sound0': open(sound0path, 'rb'), 'Sound1': open(sound1path, 'rb')}
    r = requests.post(url, files=files, data=data)
    print(r.url)
    print(r.json())
    print(time.time() - starttime, "秒")

if __name__ == "__main__":
    Speaker_1_1()
    ASR_Speaker_1_1()

