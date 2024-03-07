//
//  DefiningQueryWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

// *****************************************************
// Copyright (c) 2013 SAP AG or an SAP affiliate company. All rights reserved.
// *****************************************************

#import "MemoryTrackerBase.h"

@interface DefiningQueryWrapper : NSObject

@property (nonatomic, strong)  NSString *              name;
@property (nonatomic, strong)  NSString *              url;
@property (nonatomic, assign)  bool                    retrieveStreams;
@property (nonatomic, assign)  bool                    isRemoving;

- (id) initWithName:(NSString*)name
                url:(NSString*)url
    retrieveStreams:(bool)retrieveStreams;

- (NSString *) getRequestName;

- (NSString *) getRequestURL;

- (bool) getIsRetrieveStreams;

- (bool) getIsRemoving;

@end




