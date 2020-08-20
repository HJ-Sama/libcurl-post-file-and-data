# libcurl-post-file-and-data
利用libcurl实现文件和字段的表单上传

代码可以直接复用，地址改成服务器地址

 curl_formadd(&post, &last, CURLFORM_PTRNAME, "name", CURLFORM_PTRCONTENTS, "ggggggg", CURLFORM_END);
 实现提交字段表单，可以根据服务器字段进行修改
 
 curl_formadd(&post, &last, CURLFORM_PTRNAME, "file", CURLFORM_FILE, "1.pdf", CURLFORM_FILENAME, "1.pdf", CURLFORM_END);
 实现文件上传，第二个字段是文件路径，第三个字段是上传后的文件名称
 
 其他代码没有什么需要改动的
 
 利用libcurl前面需要很多步骤，可以参考https://blog.csdn.net/david412306524/article/details/51213104
 尽量一步都不要错，所有步骤都是为了生成libcurl.lib这个库
 
 至于从网上下载的libcurl.lib能不能用我也不太清楚
  
