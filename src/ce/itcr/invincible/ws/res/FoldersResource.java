package ce.itcr.invincible.ws.res;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

@Path("/folders")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class FoldersResource {

    private static FoldersService folders = FoldersService.getInstance();

    @GET
    @Path("/{folderId}")
    public Response getImages(@PathParam("folderId") String folderId) {
        String data = folders.getFolders(folderId);

        Response.ResponseBuilder builder = Response.ok(data);
        builder.header("folder-id:", folderId);
        if (data.isEmpty()) builder.status(404);
        else builder.status(200);
        return builder.build();
    }

    @PUT
    @Path("/{folderId}")
    public Response putImages(@PathParam("folderId") int folderId, String data) {
        boolean status = folders.putFolders(folderId, data);

        Response.ResponseBuilder builder = Response.ok();
        builder.header("folder-id:", folderId);
        if (status) builder.status(201);
        else builder.status(409);
        return builder.build();
    }

    @POST
    @Path("/{folderId}")
    public Response postImages(@PathParam("folderId") String folderId, String message) {
        String data = folders.postFolders(folderId, message);

        Response.ResponseBuilder builder = Response.ok(data);
        builder.header("folder-id:", folderId);
        if (data.isEmpty()) builder.status(404);
        else builder.status(200);
        return builder.build();
    }

    @DELETE
    @Path("/{folderId}")
    public Response deleteImages(@PathParam("folderId") String folderId) {
        boolean status = folders.deleteFolders(folderId);

        Response.ResponseBuilder builder = Response.ok();
        builder.header("folder-id:", folderId);
        if (status) builder.status(202);
        else builder.status(404);
        return builder.build();
    }
}
