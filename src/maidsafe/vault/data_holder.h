/***************************************************************************************************
 *  Copyright 2012 MaidSafe.net limited                                                            *
 *                                                                                                 *
 *  The following source code is property of MaidSafe.net limited and is not meant for external    *
 *  use.  The use of this code is governed by the licence file licence.txt found in the root of    *
 *  this directory and also on www.maidsafe.net.                                                   *
 *                                                                                                 *
 *  You are not free to copy, amend or otherwise use this source code without the explicit         *
 *  written permission of the board of directors of MaidSafe.net.                                  *
 **************************************************************************************************/

#ifndef MAIDSAFE_VAULT_DATA_HOLDER_H_
#define MAIDSAFE_VAULT_DATA_HOLDER_H_

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "boost/filesystem/path.hpp"
#include "maidsafe/routing/routing_api.h"
#include "maidsafe/nfs/network_file_system.h"
#include "maidsafe/vault/disk_based_storage.h"
#include "maidsafe/common/rsa.h"

namespace maidsafe {

namespace nfs { class Message; }

namespace vault {

typedef Nfs<NoGet, NoPut, NoPost, NoDelete> DataHolderNfs;

class DataHolder {
 public:
  DataHolder(routing::Routing& routing, const boost::filesystem::path vault_root_dir);
  ~DataHolder();
  void HandleMessage(const nfs::Message& message, reply_functor reply_func);
 private:
  void HandlePutMessage(const Message& message);
  void HandleGetMessage(const Message& message, reply_functor reply_func);
  // {
  // 
  // }
  void HandlePostMessage(const Message& message);
  void HandleDeleteMessage(const Message& message);
  boost::filesystem::path vault_root_dir_;
  routing::Routing& routing_;
  DiskBasedStorage disk_storage_;
};

}  // namespace vault

}  // namespace maidsafe

#endif  // MAIDSAFE_VAULT_DATA_HOLDER_H_