//------------------------------------------------------------------------------
/*
    This file is part of Beast: https://github.com/vinniefalco/Beast
    Copyright 2013, Vinnie Falco <vinnie.falco@gmail.com>

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef BEAST_TESTPEER_H_INCLUDED
#define BEAST_TESTPEER_H_INCLUDED

/** An abstract peer for unit tests.
*/
class TestPeer : public TestPeerBasics
{
public:
    virtual ~TestPeer () { }

    /** Get the name of this peer. */
    virtual String name () const = 0;

    /** Start the peer.
        If the peer is a server, the call will block until the
        listening socket is ready to receive connections.
    */
    virtual void start () = 0;

    /** Wait for the peer to finish.

        If the peer does not complete before the timout expires
        then a timeout error is returned. If timeoutSeconds is less
        than 0, then the wait is infinite.

        @return Any error code generated during the server operation.
    */
    virtual boost::system::error_code join (int timeoutSeconds = -1) = 0;
};

#endif