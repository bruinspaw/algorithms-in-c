/* Copyright (C) 2017, kylinsage <kylinsage@gmail.com>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <string.h>
#include "EdgeListGraph.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 0;

    EdgeListGraph graph, mst;
    egraph_init(&graph, 0);
    egraph_init(&mst, 0);

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
        exit(1);

    try {

        dot2graph(fp, &graph);
        graph2dot(stdout, &graph);

        egraph_kruskal_mst(&graph, &mst);

        egraph_write(stdout, &graph);
        egraph_write(stdout, &mst);
    }
    finally {
        fprintf(stderr, "Return code: %d\n", _except_code_);
    }

    //egraph_read(fp, &graph);
    fclose(fp);

    /* destroy graph */
    egraph_destroy(&graph);
    egraph_destroy(&mst);

    return 0;
}
