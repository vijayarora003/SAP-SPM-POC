//
//  StoreWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "MemoryTrackerBase.h"

//The following two line plus the line at end of interaface for ignoring warnings during build.

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

#if __cplusplus

namespace lodata
{
    class Store;
}

#endif

@class ActionWrapper;
@class ComplexTypeWrapper;
@class DefiningQueryWrapper;
@class EntityTypeWrapper;
@class EnumTypeWrapper;
@class OfflineODataAtomicBool;
@class OfflineODataDelegateInternal;
@class OfflineODataProviderDelegateInternal;
@class OfflineODataLoggerInternal;
@class OperationSessionInfo;
@class ResponseBatchWrapper;
@class ResponseWrapper;
@class RequestBatchWrapper;
@class RequestSingleWrapper;
@class StoreOptionsWrapper;
@class StreamWriterWrapper;
@class EdmWrapper;

@interface StoreWrapper : OBJ_WRAPPER_BASE

#if __cplusplus
- (instancetype) init;
#endif

- (BOOL) openStore: (StoreOptionsWrapper *) storeOpts
                    withParams: (NSString*) params
                    delegate: (OfflineODataDelegateInternal*) delegate
                    logger: (OfflineODataLoggerInternal*) logger
					isCancelled:(OfflineODataAtomicBool *) isCancelled
                    error: (NSError *__autoreleasing*) error;

- (BOOL) openStore: (StoreOptionsWrapper *) storeOpts
                    withParams: (NSString*) params
                    providerDelegate: (OfflineODataProviderDelegateInternal*) providerDelegate
                    logger: (OfflineODataLoggerInternal*) logger
                    isCancelled:(OfflineODataAtomicBool *) isCancelled
                    sessionInfo:(OperationSessionInfo*) sessionInfo
                    error: (NSError *__autoreleasing*) error;

- (BOOL) refresh:(NSString *) refreshSubset
                    mergeStreamParameters:(NSString *) parameters
                    isCancelled:(OfflineODataAtomicBool *) isCancelled
                    sessionInfo:(OperationSessionInfo*) sessionInfo
                    error:(NSError *__autoreleasing*) error;

- (BOOL) removeDefiningQuery: (NSString *) definingQuery
                       error: (NSError *__autoreleasing*) error;

- (BOOL) getRequestQueueIsEmpty:(StoreOptionsWrapper *) storeOpts
                          error:(NSError *__autoreleasing*) error NS_SWIFT_NOTHROW;

- (BOOL) getHasPendingRefresh:(NSError *__autoreleasing*) error NS_SWIFT_NOTHROW;

- (BOOL) getHasPendingFlush:(NSError *__autoreleasing*) error NS_SWIFT_NOTHROW;

- (BOOL) close:(NSError *__autoreleasing*) error;

- (ResponseWrapper *) executeRequest:(RequestSingleWrapper *) requestWrapper
                        error:(NSError *__autoreleasing*) error;

- (ResponseBatchWrapper *) executeBatchRequest:(RequestBatchWrapper *) requestBatchWrapper
                        error:(NSError *__autoreleasing*) error;

- (BOOL) flushQueuedRequests:(NSString *) mergeStreamParameters
                    isCancelled:(OfflineODataAtomicBool *) isCancelled
                    sessionInfo:(OperationSessionInfo*) sessionInfo
                    error:(NSError *__autoreleasing*) error;

- (BOOL) flushQueuedRequests:(NSString *) mergeStreamParameters
                 isCancelled:(OfflineODataAtomicBool *) isCancelled
                  categories:(NSArray * ) categories
               numCategories:(size_t) numCategories
                    sessionInfo:(OperationSessionInfo*) sessionInfo
                       error:(NSError *__autoreleasing*) error;

- (BOOL) cancelDownload:(NSError *__autoreleasing*) error;

- (BOOL) cancelUpload:(NSError *__autoreleasing*) error;

- (BOOL) AddDefiningQuery:(const char *) reqName
                    url:(const char *) url
                    retrieveStreams:(BOOL) retrieveStreams
                    error:(NSError *__autoreleasing*) error;

-(BOOL) SetDefiningQueryGroups:(const char*) groups
                    error:(NSError *__autoreleasing*) error;

- (BOOL) unregisterStreamRequest:(const char *) registerName
                    error:(NSError *__autoreleasing*) error;

- (NSString *) getEntitySetFromEntityType:(NSString *) entityTypeName
                    error:(NSError *__autoreleasing*) error;

- (const EntityTypeWrapper *) getEntityTypeByName:(NSString *) qualifiedEntityTypeName
											error:(NSError *__autoreleasing*) error;

- (const ComplexTypeWrapper *) getComplexTypeByName:(NSString *) qualifiedComplexTypeName
											  error:(NSError *__autoreleasing*) error;

- (const EnumTypeWrapper *) getEnumTypeByName:(NSString *) qualifiedEnumTypeName
											  error:(NSError *__autoreleasing*) error;

- (NSString *) getSystemProxyStreamParams:(NSString *) authURL;

- (StreamWriterWrapper *) createStreamWriter: (RequestSingleWrapper *) request
                    error:(NSError *__autoreleasing*) error;

- (const ActionWrapper * ) getActionFromURL: (NSString *) url
                                   error:(NSError *__autoreleasing*) error;

#if DEBUG
    - (void) setLODataTestCallbacks: (NSInteger (^ _Nonnull)(NSInteger, NSInteger))lodataTestCallback;
	- (void) clearTestCallbacks;
#endif

- (BOOL) pingServer: (NSString *) mergeStreamParameters
			  error:(NSError *__autoreleasing*) error;

- (BOOL) sendStore: (NSString *) mergeStreamParameters
                    sessionInfo:(OperationSessionInfo*) sessionInfo
                    newEncryptionKey: (NSString *) newEncryptionKey
                    error: (NSError *__autoreleasing*) error;

- (NSString *) printRequestQueue: (NSError *__autoreleasing*) error;

- (NSString *) printDefiningRequests: (NSError *__autoreleasing*) error;

- (NSMutableArray *) getDefiningQueries: (NSError *__autoreleasing*) error;

- (BOOL) undoPendingChanges: (NSString *) editLink
                      error: (NSError *__autoreleasing*) error;

- (BOOL) undoPendingChanges: (NSArray * ) entities
                    numEntities:(size_t) numEntities
                    error: (NSError *__autoreleasing*) error;

- (void) getPreviousUser: (StoreOptionsWrapper *) storeOpts
                   userId: (NSString* __autoreleasing*) userId
                   error: (NSError *__autoreleasing*) error;

- (OfflineODataDelegateInternal *) getDelegate;

- (OfflineODataProviderDelegateInternal *) getProviderDelegate;

- (OfflineODataLoggerInternal *) getLogger;

- (int64_t) getStoreVersion;

- (EdmWrapper *) getEdmWrapper;

- (NSString *) getODataVersion;

- (void) updateClientOnlySchema : (NSArray * ) statements
                    numStatements: (size_t) numStatements
                    metadata: (NSString *) metadata
                    error: (NSError *__autoreleasing*) error
                    forceUpgrade: (BOOL) forceUpgrade;

- (NSString *) getClientOnlyMetadata : (NSError *__autoreleasing*) error NS_SWIFT_NOTHROW;

- (BOOL) hasClientOnlySchema;

- (void) purgeClientOnlyData : (BOOL) dropDataSchema
                    error: (NSError *__autoreleasing*) error NS_SWIFT_NOTHROW;

@end
#pragma clang diagnostic pop
