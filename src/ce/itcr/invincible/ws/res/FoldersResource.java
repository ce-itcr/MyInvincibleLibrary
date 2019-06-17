package ce.itcr.invincible.ws.res;

import ce.itcr.invincible.data.Image;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import java.util.List;

@Path("/folders")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class FoldersResource {

    private static FoldersService folders = FoldersService.getInstance();

    @GET
    @Path("/{folderId}")
    public Response getImages(@PathParam("folderId") String folderId) {
        List<Image> data = folders.getFolders(folderId);

        Response.ResponseBuilder builder = Response.ok(data);
        builder.header("folder-id:", folderId);
        if (data.isEmpty()) builder.status(404);
        else builder.status(200);
        return builder.build();
    }

    @PUT
    @Path("/{folderId}")
    public Response putImages(@PathParam("folderId") String folderId, List<Image> images) {
        boolean status = folders.putFolders(folderId, images);
        long subFoldersCount = folders.countSubFolders(folderId);

        Response.ResponseBuilder builder = Response.ok();
        builder.header("folder-id:", folderId);
        builder.header("subFoldersCount:", subFoldersCount);
        if (status) builder.status(201);
        else builder.status(409);
        return builder.build();
    }

    @POST
    @Path("/{folderId}")
    public Response postImages(@PathParam("folderId") String folderId, List<Image> images) {
        List<Image>  data = folders.postFolders(folderId, images);
        long subFoldersCount = folders.countSubFolders(folderId);

        Response.ResponseBuilder builder = Response.ok(data);
        builder.header("folder-id:", folderId);
        builder.header("subFoldersCount:", subFoldersCount);
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

    @PUT
    @Path("/sub/{parentId}")
    public Response putFolder(@PathParam("parentId") String parentId) {
        long folderId = folders.createSubFolder(parentId);

        Response.ResponseBuilder builder = Response.ok();
        builder.header("folder-id:", folderId);
        builder.status(201);
        return builder.build();
    }

    @DELETE
    @Path("/sub/{folderId}")
    public Response deleteFolder(@PathParam("folderId") String folderId) {
        folders.deleteSubFolders(folderId);

        Response.ResponseBuilder builder = Response.ok();
        builder.header("folder-id:", folderId);
        builder.status(201);
        return builder.build();
    }
}
