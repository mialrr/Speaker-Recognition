#################################################
#Speaker_1_1 1:1 检测两个声音是不是同一个人的声音
#################################################
#import <Foundation/Foundation.h>

dispatch_semaphore_t sema = dispatch_semaphore_create(0);

NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"http://47.110.142.112:9999"]
  cachePolicy:NSURLRequestUseProtocolCachePolicy
  timeoutInterval:10.0];
NSArray *parameters = @[
  @{ @"name": @"AppID", @"value": @"2rtg2z53r" }, 
  @{ @"name": @"APIKey", @"value": @"378d4582ad3ed253057cafe9c70fae8b" }, 
  @{ @"name": @"SecretKey", @"value": @"d6uk5fd" }, 
  @{ @"name": @"Sound0", @"fileName": @"../sample-files/156_0.wav" },
  @{ @"name": @"Sound1", @"fileName": @"../sample-files/156_1.wav" }
];

NSString *boundary = @"----WebKitFormBoundary7MA4YWxkTrZu0gW";
NSError *error;
NSMutableString *body = [NSMutableString string];

for (NSDictionary *param in parameters) {
  [body appendFormat:@"--%@\r\n", boundary];
  if (param[@"fileName"]) {
    [body appendFormat:@"Content-Disposition:form-data; name=\"%@\"; filename=\"%@\"\r\n", param[@"name"], param[@"fileName"]];
    [body appendFormat:@"Content-Type: %@\r\n\r\n", param[@"contentType"]];
    [body appendFormat:@"%@", [NSString stringWithContentsOfFile:param[@"fileName"] encoding:NSUTF8StringEncoding error:&error]];
    if (error) {
      NSLog(@"%@", error);
    }
  } else {
    [body appendFormat:@"Content-Disposition:form-data; name=\"%@\"\r\n\r\n", param[@"name"]];
    [body appendFormat:@"%@", param[@"value"]];
  }
}
[body appendFormat:@"\r\n--%@--\r\n", boundary];
NSData *postData = [body dataUsingEncoding:NSUTF8StringEncoding];
[request setHTTPBody:postData];

[request setHTTPMethod:@"POST"];

NSURLSession *session = [NSURLSession sharedSession];
NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request
completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
  if (error) {
    NSLog(@"%@", error);
  } else {
    NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
    NSError *parseError = nil;
    NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&parseError];
    NSLog(@"%@",responseDictionary);
    dispatch_semaphore_signal(sema);
  }
}];
[dataTask resume];
dispatch_semaphore_wait(sema, DISPATCH_TIME_FOREVER);


#################################################
# ASR_Speaker_1_1 认证分为两部分
# 1:检测是否说了指定的文字的语音
# 2:检测是不是同一个人的声纹
# SpkTxt是语音Sound0的文本
#################################################
#import <Foundation/Foundation.h>

dispatch_semaphore_t sema = dispatch_semaphore_create(0);

NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"http://47.110.142.112:9999"]
  cachePolicy:NSURLRequestUseProtocolCachePolicy
  timeoutInterval:10.0];
NSArray *parameters = @[
  @{ @"name": @"AppID", @"value": @"2rtg2z53r" }, 
  @{ @"name": @"APIKey", @"value": @"378d4582ad3ed253057cafe9c70fae8b" }, 
  @{ @"name": @"SecretKey", @"value": @"d6uk5fd" }, 
  @{ @"name": @"Sound0", @"fileName": @"../sample-files/76256_39.wav" },
  @{ @"name": @"Sound1", @"fileName": @"../sample-files/156_1.wav" },
  @{ @"name": @"Language", @"value": @"cn" }, 
  @{ @"name": @"SpkTxt", @"value": @"他完全将自己当成了一个凡人在体会这人世间的生老病死悲欢离合" }
];

NSString *boundary = @"----WebKitFormBoundary7MA4YWxkTrZu0gW";
NSError *error;
NSMutableString *body = [NSMutableString string];

for (NSDictionary *param in parameters) {
  [body appendFormat:@"--%@\r\n", boundary];
  if (param[@"fileName"]) {
    [body appendFormat:@"Content-Disposition:form-data; name=\"%@\"; filename=\"%@\"\r\n", param[@"name"], param[@"fileName"]];
    [body appendFormat:@"Content-Type: %@\r\n\r\n", param[@"contentType"]];
    [body appendFormat:@"%@", [NSString stringWithContentsOfFile:param[@"fileName"] encoding:NSUTF8StringEncoding error:&error]];
    if (error) {
      NSLog(@"%@", error);
    }
  } else {
    [body appendFormat:@"Content-Disposition:form-data; name=\"%@\"\r\n\r\n", param[@"name"]];
    [body appendFormat:@"%@", param[@"value"]];
  }
}
[body appendFormat:@"\r\n--%@--\r\n", boundary];
NSData *postData = [body dataUsingEncoding:NSUTF8StringEncoding];
[request setHTTPBody:postData];

[request setHTTPMethod:@"POST"];

NSURLSession *session = [NSURLSession sharedSession];
NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request
completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
  if (error) {
    NSLog(@"%@", error);
  } else {
    NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
    NSError *parseError = nil;
    NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&parseError];
    NSLog(@"%@",responseDictionary);
    dispatch_semaphore_signal(sema);
  }
}];
[dataTask resume];
dispatch_semaphore_wait(sema, DISPATCH_TIME_FOREVER);
