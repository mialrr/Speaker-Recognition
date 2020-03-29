#################################################
#Speaker_1_1 1:1 检测两个声音是不是同一个人的声音
#################################################
<?php
require_once 'HTTP/Request2.php';
$request = new HTTP_Request2();
$request->setUrl('http://47.110.142.112:9999');
$request->setMethod(HTTP_Request2::METHOD_POST);
$request->setConfig(array(
  'follow_redirects' => TRUE
));
$request->addPostParameter(array(
  'AppID' => '2rtg2z53r',
  'APIKey' => '378d4582ad3ed253057cafe9c70fae8b',
  'SecretKey' => 'd6uk5fd'
));
$request->addUpload('Sound0', "../sample-files/76256_39.wav", "../sample-files/76256_39.wav", '<Content-Type Header>');
$request->addUpload('Sound1', "../sample-files/156_1.wav", "../sample-files/156_1.wav", '<Content-Type Header>');
try {
  $response = $request->send();
  if ($response->getStatus() == 200) {
    echo $response->getBody();
  }
  else {
    echo 'Unexpected HTTP status: ' . $response->getStatus() . ' ' .
    $response->getReasonPhrase();
  }
}
catch(HTTP_Request2_Exception $e) {
  echo 'Error: ' . $e->getMessage();
}



#################################################
# ASR_Speaker_1_1 认证分为两部分
# 1:检测是否说了指定的文字的语音
# 2:检测是不是同一个人的声纹
# SpkTxt是语音Sound0的文本
#################################################
<?php
require_once 'HTTP/Request2.php';
$request = new HTTP_Request2();
$request->setUrl('http://47.110.142.112:9999');
$request->setMethod(HTTP_Request2::METHOD_POST);
$request->setConfig(array(
  'follow_redirects' => TRUE
));
$request->addPostParameter(array(
  'AppID' => '2rtg2z53r',
  'APIKey' => '378d4582ad3ed253057cafe9c70fae8b',
  'SecretKey' => 'd6uk5fd',
  'Language' => 'cn',
  'SpkTxt' => '他完全将自己当成了一个凡人在体会这人世间的生老病死悲欢离合'
));
$request->addUpload('Sound0', "../sample-files/76256_39.wav", "../sample-files/76256_39.wav", '<Content-Type Header>');
$request->addUpload('Sound1', "../sample-files/156_1.wav", "../sample-files/156_1.wav", '<Content-Type Header>');
try {
  $response = $request->send();
  if ($response->getStatus() == 200) {
    echo $response->getBody();
  }
  else {
    echo 'Unexpected HTTP status: ' . $response->getStatus() . ' ' .
    $response->getReasonPhrase();
  }
}
catch(HTTP_Request2_Exception $e) {
  echo 'Error: ' . $e->getMessage();
}
