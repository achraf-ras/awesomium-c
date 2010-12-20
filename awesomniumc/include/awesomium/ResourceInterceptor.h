/**
 * @file ResourceInterceptor.h
 *
 * @author
 *
 * This file is a part of Awesomium, a library that makes it easy for 
 * developers to embed the web in their applications.
 *
 * Website: <http://www.khrona.com/products/awesomium>
 * 
 * Copyright (C) 2010 Khrona. All rights reserved. Awesomium is a 
 * trademark of Khrona.
 */

#ifndef __AWESOMIUM_RESOURCE_INTERCEPTOR_H__
#define __AWESOMIUM_RESOURCE_INTERCEPTOR_H__

#include <string>
#include <sstream>
#include "PlatformUtils.h"

#if __LP64__
typedef long		int64;
#else
typedef long long	int64;
#endif

namespace Awesomium {
	
class WebView;
class ResourceResponse;
struct ResourceResponseMetrics;

/**
 * The ResourceInterceptor class is used to intercept requests and responses 
 * for resources via WebView::setResourceInterceptor. This can be used for
 * responding to resource requests using your own custom resource loading
 * scheme or for tracking resource loads.
 */
class _OSMExport ResourceInterceptor
{
public:
	/**
	 * Override this method to intercept requests for resources. You can use 
	 * this to respond to requests using your own custom resource-loading
	 * back-end or to monitor requests for tracking purposes.
	 *
	 * @param	caller	The WebView instance that invoked the request.
	 *
	 * @param	url		The URL of the request.
	 *
	 * @param	referrer	The referrer of the request.
	 *
	 * @return	Return a new ResourceResponse (see ResourceResponse::Create)
	 *          to override the response, otherwise, return NULL to allow 
	 *          normal behavior.
	 */
	virtual Awesomium::ResourceResponse* onRequest(Awesomium::WebView* caller, 
												   const std::string& url, 
												   const std::string& referrer) {
		return NULL;
	}
	
	/**
	 * Override this method to intercept responses to requests. You can use
	 * this for tracking/statistics purposes.
	 *
	 * @param	caller		The WebView instance that invoked the response.
	 *
	 * @param	url			The URL of the response.
	 *
	 * @param	statusCode	The HTTP status code of the response. For non-HTTP
	 *						responses, 200 represents "success" and 404
	 *						represents "failure".
	 *
	 * @param	metrics		Various informative metrics about the response.
	 */
	virtual void onResponse(Awesomium::WebView* caller, 
							const std::string& url, int statusCode, 
							const Awesomium::ResourceResponseMetrics& metrics) {}
};

/**
 * The ResourceResponse class is simply a wrapper around a raw block of data and 
 * a specified mime-type. It can be used with ResourceInterceptor::onRequest 
 * to return a custom resource for a certain resource request.
 */
class _OSMExport ResourceResponse
{
public:
	/**
	 * Create a ResourceResponse from a raw block of data. (Data is not owned,
	 * a copy is made of the supplied buffer.)
	 * 
	 * @param	numBytes	Size (in bytes) of the memory buffer.
	 *
	 * @param	buffer		Raw memory buffer to be copied.
	 *
	 * @param	mimeType	The mime-type of the data.
	 *                      See <http://en.wikipedia.org/wiki/Internet_media_type>
	 */
	static ResourceResponse* Create(size_t numBytes, unsigned char* buffer, 
									const std::string& mimeType);

	/**
	 * Create a ResourceResponse from a file on disk.
	 *
	 * @param	filePath	The path to the file.
	 */
	static ResourceResponse* Create(const std::wstring& filePath);

protected:

	ResourceResponse(size_t numBytes, unsigned char* buffer, 
					 const std::string& mimeType);
	ResourceResponse(const std::wstring& filePath);

	~ResourceResponse();
	
	size_t numBytes;
	unsigned char* buffer;
    std::string mimeType;
	std::wstring filePath;

	friend class WebCoreImpl;
};
	
/**
 * Various informative statistics about a certain resource response.
 */
struct _OSMExport ResourceResponseMetrics
{
	/// Whether or not the resource was cached
	bool wasCached;
	
	/// The time of the request, in milliseconds
	int64 requestTimeMs;
	
	/// The time that the response began, in milliseconds
	int64 responseTimeMs;
	
	/// The expected content size given by the server
	int64 expectedContentSize;
	
	/// The mime-type of the response
	std::string mimeType;
};

}

#endif