#import "OSXMenuActions.h"

@implementation OSXMenuActions

- (id)init:(OSXActionsRunner *)init_actionsRunner
{
  self = [super init];
  actionsRunner = init_actionsRunner;
  return self;
}

- (void) runAction: (id)sender
{
  actionsRunner->run_action(1);
  printf ("Hello!\n");
}
@end
